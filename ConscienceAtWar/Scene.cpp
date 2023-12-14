#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <future>
#include <iomanip>
#include <conio.h>

#include <windows.h>

#include "Paragraph.h"
#include "Choice.h"
#include "utils.h"
#include "Program.h"

#include "Scene.h"


Scene::Scene(std::string name, std::vector<Paragraph> paragraphs, std::vector<Choice> choices, int timer) {
    this->name = name;
    this->paragraphs = paragraphs;
    this->choices = choices;
    this->timer = timer;
}

void MoveToConsoleLine(int line) {
    std::cout << "\033[" << line << ";0H";
}

void GetUserChoice(int& playerChoice) {
    playerChoice = _getch() - '0';
}

bool ConditionVerification(std::vector<Condition> conditions) {
    if (conditions.size() == 0) return true; // If there is no conditions, return true

    bool result = true;

    for (int i = 0; i < conditions.size(); i++)
    {
        result = result && conditions[i].IsVerified();
    }

    return result;
}
void ActivateActions(std::vector<Action> actions) {
    for (int i = 0; i < actions.size(); i++)
    {
        actions[i].Activate();
    }
}

void Scene::Display(std::vector<Scene> scenes) {
    int timerDisplayPos = 0;
    int paragraphsDisplayPos = timerDisplayPos + 5;
    int choicesDisplayPos = paragraphsDisplayPos + 15;

    int inputNumber = 1;

    std::string tmp;

    if (name == "Scene 1") {
        utils::ResetInventory();
        utils::ResetKarma();
    }
    else if (name == "QuitScene") {
        exit(0);
    }

    system("cls");

    MoveToConsoleLine(timerDisplayPos);
    std::cout << " -------------------" << std::endl;
    std::cout << "\033[2K\r";
    if (timer <= 0) {
        std::cout << "| Time left : NONE  |" << std::endl;
    }
    else if (timer < 10) {
        std::cout << "| Time left : 0" << timer << ".00 |" << std::endl;
    }
    else {
        std::cout << "| Time left : " << timer << ".00 |" << std::endl;
    }
    std::cout << " -------------------" << std::endl;

    MoveToConsoleLine(paragraphsDisplayPos);

    std::cout << "-------------------------------------------------------------------------------------------------------------" << std::endl<<std::endl;

    for (int i = 0; i < paragraphs.size(); i++) {
        if (paragraphs[i].timeOffSet <= 0) {
            std::cout << "-> "; paragraphs[i].Display(10); std::cout << std::endl;
            paragraphsDisplayPos++;
        }
    }

    MoveToConsoleLine(choicesDisplayPos);

    std::cout << "-------------------------------------------------------------------------------------------------------------" << std::endl;
    choicesDisplayPos += 2;

    MoveToConsoleLine(choicesDisplayPos);

    for (int i = 0; i < choices.size(); i++) {
        if (choices[i].timeOffSet <= 0 && ConditionVerification(choices[i].conditions)) {
            std::cout << inputNumber << ". "; choices[i].Display(10);
            inputNumber++;
            choicesDisplayPos++;
        }
    }
    int playerChoice = -1;
    while (_kbhit()) {
        playerChoice = _getch();
    }
    auto future = std::async(GetUserChoice, std::ref(playerChoice));

    auto start_time = std::chrono::steady_clock::now();
    auto end_time = start_time + std::chrono::milliseconds(timer * 1000);
    bool displayed = false;

    while (std::chrono::steady_clock::now() < end_time || timer <= 0) {
        if (future.wait_for(std::chrono::milliseconds(0)) != std::future_status::ready) {
            auto current_time = std::chrono::steady_clock::now();
            auto remaining_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - current_time).count() / 1000.0;

            for (int i = 0; i < paragraphs.size(); i++) {
                if (paragraphs[i].displayed == false && paragraphs[i].timeOffSet > 0 && ConditionVerification(paragraphs[i].conditions)) {
                    if (std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count() >= paragraphs[i].timeOffSet * 1000) {
                        paragraphs[i].displayed = true;
                        MoveToConsoleLine(paragraphsDisplayPos);
                        paragraphsDisplayPos++;
                        paragraphs[i].Display(10);
                        if (paragraphs[i].actions.size() > 0) ActivateActions(paragraphs[i].actions);
                    }
                }
            }
            for (int i = 0; i < choices.size(); i++) {
                if (choices[i].displayed == false && choices[i].timeOffSet > 0 && ConditionVerification(choices[i].conditions)) {
                    if (std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count() >= choices[i].timeOffSet * 1000) {
                        choices[i].displayed = true;
                        MoveToConsoleLine(choicesDisplayPos);
                        std::cout << inputNumber << ". "; choices[i].Display(10);
                        inputNumber++;
                        choicesDisplayPos++;
                    }
                }
            }
            // Affichage du temps restant
            if (timer > 0) {
                MoveToConsoleLine(timerDisplayPos);
                std::cout << std::endl;
                std::cout << "\033[2K\r";
                std::cout << "| Time left : 0" << std::fixed << std::setprecision(2) << remaining_time << " |" << std::flush;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        else if (future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) { //Input du joueur
            if (playerChoice > 0 && playerChoice < inputNumber) {
                playerChoice -= 1;
                for (int i = 0; i < scenes.size(); i++) {
                    if (choices[playerChoice].link == scenes[i].name) {
                        if (choices[playerChoice].actions.size() > 0) ActivateActions(choices[playerChoice].actions);
                        system("cls");
                        scenes[i].Display(scenes);
                    }
                }
            }
            else {
                future = std::async(GetUserChoice, std::ref(playerChoice));
            }
        }
    }
    scenes[0].Display(scenes);
}