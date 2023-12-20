#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <future>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <ctime>

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

void MoveToConsoleLine(int line) { //move console cursor
    std::cout << "\033[" << line << ";0H";
}

void GetUserChoice(int& playerChoice) { //get user choice
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
void ActivateActions(std::vector<Action> actions) { //activate action 
    for (int i = 0; i < actions.size(); i++)
    {
        actions[i].Activate();
    }
}

int GetCenter() { //get showed console size
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void PrintLine(int lengh) {
    for (int i = 0; i <= lengh + 1; i++) {
        std::cout << (char)205;
    }
}

void PrintSpace(int lengh) {
    for (int i = 0; i <= lengh + 1; i++) {
        std::cout << " ";
    }
}

void MyTimer(int lengh, std::string timerText) //print timer
{
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    PrintSpace((lengh / 2) - timerText.size());
    std::cout << (char)201;
    PrintLine(timerText.size());

    std::cout << (char)187 << "\n";
    PrintSpace((lengh / 2) - timerText.size());
    std::cout << (char)197 << " " << timerText << " " << (char)197 << "\n";

    PrintSpace((lengh / 2) - timerText.size());
    std::cout << (char)200;
    PrintLine(timerText.size());
    std::cout << (char)188;
}

void Scene::Display(std::vector<Scene> scenes) { //main displayer
    srand(static_cast<unsigned int>(time(nullptr)));

    std::string timerText;
    timer <= 0 ? timerText = "                 "
        : timer < 10 ? timerText = "Time left : 0" + std::to_string(timer) + ".00s"
            : timerText = "Time left : " + std::to_string(timer) + ".00s";

    int paragraphsDisplayPos = 5;
    int choicesDisplayPos = paragraphsDisplayPos + 15;
    int inputNumber = 1;

    srand(time(0));

    std::string tmp;

    if (name == "Scene 1") {
        utils::ResetInventory();
        utils::ResetKarma();
    }
    else if (name == "QuitScene") {
        exit(0);
    }

    system("cls");

    MyTimer(GetCenter(), timerText); // print timer

    MoveToConsoleLine(paragraphsDisplayPos - 1);

    PrintSpace(1);
    std::cout << (char)201;
    PrintLine(GetCenter() - 10);
    std::cout << (char)187 << "\n";

    for (int i = 0; i < 15; i++) {
        PrintSpace(1);
        std::cout << (char)186; PrintSpace(GetCenter() - 10); std::cout << (char)186 << "\n";
    }

    MoveToConsoleLine(choicesDisplayPos);

    PrintSpace(1);
    std::cout << (char)200;
    PrintLine(15);
    std::cout << (char)203;
    PrintLine(GetCenter()-46);
    std::cout << (char)203;
    PrintLine(15);
    std::cout << (char)188 << "\n";

    for (int i = 0; i < 8; i++) {
        PrintSpace(19);
        std::cout << (char)186; PrintSpace(GetCenter() - 46); std::cout << (char)186 << "\n";
    }

    PrintSpace(19);
    std::cout << (char)200;
    PrintLine(GetCenter() - 46);
    std::cout << (char)188;

    MoveToConsoleLine(paragraphsDisplayPos);

    for (int i = 0; i < paragraphs.size(); i++) { //base paragraph display
        if (paragraphs[i].timeOffSet <= 0 && ConditionVerification(paragraphs[i].conditions)) {
            paragraphsDisplayPos += paragraphs[i].text.size() / (GetCenter() - 18) + 2;
            paragraphs[i].Display(GetCenter(), 10);
            if (paragraphs[i].actions.size() > 0) ActivateActions(paragraphs[i].actions);
        }
    }

    choicesDisplayPos += 2;

    MoveToConsoleLine(choicesDisplayPos);

    for (int i = 0; i < choices.size(); i++) { //base choice display
        if (choices[i].timeOffSet <= 0 && ConditionVerification(choices[i].conditions)) {
            choices[i].Display(GetCenter(), 0, inputNumber);
            inputNumber++;
            choices[i].text.size() >= GetCenter() - 54 ? choicesDisplayPos += 2 : choicesDisplayPos++;
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

    while (std::chrono::steady_clock::now() < end_time || timer <= 0) { //timer
        if (future.wait_for(std::chrono::milliseconds(0)) != std::future_status::ready) {
            auto current_time = std::chrono::steady_clock::now();
            auto remaining_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - current_time).count() / 1000.0;

            for (int i = 0; i < paragraphs.size(); i++) { //new paragraph after delay displayer
                if (paragraphs[i].displayed == false && paragraphs[i].timeOffSet > 0 && ConditionVerification(paragraphs[i].conditions)) {
                    if (std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count() >= paragraphs[i].timeOffSet * 1000) {
                        paragraphs[i].displayed = true;
                        MoveToConsoleLine(paragraphsDisplayPos);
                        paragraphsDisplayPos++;
                        paragraphs[i].Display(GetCenter(), 10);
                        if (paragraphs[i].actions.size() > 0) ActivateActions(paragraphs[i].actions);
                    }
                }
            }
            for (int i = 0; i < choices.size(); i++) { //new choice after delay displayer
                if (choices[i].displayed == false && choices[i].timeOffSet > 0 && ConditionVerification(choices[i].conditions)) {
                    if (std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count() >= choices[i].timeOffSet * 1000) {
                        choices[i].displayed = true;
                        MoveToConsoleLine(choicesDisplayPos);
                        choices[i].Display(GetCenter(), 0, inputNumber);
                        inputNumber++;
                        choices[i].text.size() >= GetCenter() - 54 ? choicesDisplayPos += 2 : choicesDisplayPos++;
                    }
                }
            }
            //time left display
            if (timer > 0) {
                MoveToConsoleLine(0);
                std::cout << std::endl;
                std::cout << "\033[2K\r";
                PrintSpace((GetCenter() / 2) - timerText.size());
                remaining_time < 10 ? std::cout << "| Time left : 0" << std::fixed << std::setprecision(2) << remaining_time << "s " << (char)197 << std::flush
                    : std::cout << "| Time left : " << std::fixed << std::setprecision(2) << remaining_time << "s " << (char)197 << std::flush;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        else if (future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) { //on player input
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
                future = std::async(GetUserChoice, std::ref(playerChoice)); //bad player input
            }
        }
    }
    keybd_event('A', 0, 0, 0);
    keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
    inputNumber -= 1;
    playerChoice = rand() % inputNumber;
    for (int i = 0; i < scenes.size(); i++) {
        if (choices[playerChoice].link == scenes[i].name) {
            if (choices[playerChoice].actions.size() > 0) ActivateActions(choices[playerChoice].actions);
            system("cls");
            scenes[i].Display(scenes);
        }
    }
}