#include "Scene.h"
Scene::Scene(string name, vector<Paragraph> paragraphs, vector<Choice> choices, int timer) {
	this->name = name;
	this->paragraphs = paragraphs;
	this->choices = choices;
	this->timer = timer;
}

void moveToConsoleLine(int line) {
    std::cout << "\033[" << line << ";0H";
}

void getUserChoice(int& playerChoice) {
    playerChoice = _getch() - '0';
}

void Scene::Display(vector<Scene> scene) {
    bool inputed = false;

    int writeSpeed = 17;

    int timerDisplayPos = 2;
    int paragraphsDisplayPos = timerDisplayPos + 3;
    int choicesDisplayPos = paragraphsDisplayPos + 8;

    int inputNumber = 1;

    system("cls");
    cout << "Scene : " << name<<endl;

    moveToConsoleLine(timerDisplayPos);

    std::cout << "\033[2K\r" << std::endl;
    cout << "Temps restant : " << timer << ".00 secondes";

    moveToConsoleLine(paragraphsDisplayPos);

    for (int i = 0; i < paragraphs.size(); i++) {
        if (paragraphs[i].timeOffSet <= 0) {
            paragraphs[i].Display(writeSpeed);
            paragraphsDisplayPos++;
        }
    }

    moveToConsoleLine(choicesDisplayPos);

    cout << "-----------------------------------------"<<endl;
    choicesDisplayPos += 2;

    moveToConsoleLine(choicesDisplayPos);

    for (int i = 0; i < choices.size(); i++) {
        if (choices[i].timeOffSet <= 0) {          
            cout << inputNumber << ". "; choices[i].Display(10);
            inputNumber++;
            choicesDisplayPos++;
        }
    }

    int playerChoice = -1;

    auto future = async(getUserChoice, ref(playerChoice));

    auto start_time = std::chrono::steady_clock::now();
    auto end_time = start_time + std::chrono::milliseconds(timer * 1000);
    bool messageDisplayed = false;

    while ((std::chrono::steady_clock::now() < end_time) && playerChoice == -1) {
        auto current_time = std::chrono::steady_clock::now();
        auto remaining_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - current_time).count() / 1000.0;

        for (int i = 0; i < paragraphs.size(); i++) {
            if (paragraphs[i].displayed == false && paragraphs[i].timeOffSet > 0) {
                if (std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count() >= paragraphs[i].timeOffSet * 1000) {
                    paragraphs[i].displayed = true;
                    moveToConsoleLine(paragraphsDisplayPos);
                    paragraphsDisplayPos++;
                    paragraphs[i].Display(writeSpeed);
                }
            }
        }
        for (int i = 0; i < choices.size(); i++) {
            if (choices[i].displayed == false && choices[i].timeOffSet > 0) {
                if (std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count() >= choices[i].timeOffSet * 1000) {
                    choices[i].displayed = true;
                    moveToConsoleLine(choicesDisplayPos);
                    cout << inputNumber << ". "; choices[i].Display(writeSpeed);
                    inputNumber++;
                    choicesDisplayPos++;
                }
            }
        }
        // Affichage du temps restant
        moveToConsoleLine(timerDisplayPos);
        std::cout << "\033[2K\r" << std::endl;       
        std::cout << "Temps restant : " << std::fixed << std::setprecision(2) << remaining_time << " secondes" << std::flush;

        

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    if ((future.wait_for(chrono::seconds(0)) == future_status::ready || timer <= 0) && playerChoice < inputNumber) { //Input du joueur
        future.get();
        for (int n = 0; n <= scene.size(); n++) {
            if (playerChoice == n + 1) {
                for (int i = 0; i < scene.size(); i++) {
                    if (choices[n].link == scene[i].name) {
                        system("cls");
                        scene[i].Display(scene);
                    }
                }
            }
        }
    }
    else if(playerChoice < inputNumber){
        if (timer > 0) {
            scene[2].Display(scene); //Fin du chrono
        }
    }
    else {
        scene[2].Display(scene); //Mauvais input
    }
}