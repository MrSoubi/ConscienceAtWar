#include "Scene.h"
Scene::Scene(string name, vector<Paragraph> paragraphs, vector<Choice> choices, int timer) {
	this->name = name;
	this->paragraphs = paragraphs;
	this->choices = choices;
	this->timer = timer;
}

void getUserChoice(int& playerChoice) {
    playerChoice = _getch() - '0';
}

void Scene::Display(vector<Scene> scene) {
    bool updatedScene = false;
    int newChoiceIndex = -1;

    system("cls");
    cout << this->name << endl << endl;

    for (Paragraph paragraph : paragraphs) {
        paragraph.Display(50);
    }

    cout << endl;

    for (int i = 0; i < choices.size(); i++) {
        if (choices[i].timeOffSet != 0) {
            newChoiceIndex = i;
        }
        else {
            cout << i + 1 << ". "; choices[i].Display(50);
        }
    }

    cout << endl;
 
    int playerChoice = -1;
    auto future = async(getUserChoice, ref(playerChoice));

    auto start_time = chrono::steady_clock::now();

    while (chrono::steady_clock::now() - start_time < chrono::milliseconds(timer * 1000)
        && future.wait_for(chrono::milliseconds(0)) != future_status::ready)
    {
        for (int i = timer * 1000; i >= 0 && future.wait_for(chrono::milliseconds(0)) != future_status::ready; i -= 20) {
            if (newChoiceIndex >= 0) {
                if (chrono::steady_clock::now() - start_time >= chrono::seconds(choices[newChoiceIndex].timeOffSet) && !updatedScene) {        
                    system("cls");
                    cout << this->name << endl << endl;
                    for (Paragraph paragraph : paragraphs) {
                        paragraph.Display(0);
                    }

                    cout << endl;

                    for (int i = 0; i < choices.size(); i++) {
                        cout << i + 1 << ". "; choices[i].Display(0);
                    }
                    cout << endl;
                    updatedScene = true;
                }
            } 
            std::cout << "\rTemps restant : " << std::fixed << std::setprecision(2) << static_cast<double>(i) / 1000.0 << " secondes" << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }

    if (future.wait_for(chrono::milliseconds(0)) == future_status::ready) {
        future.get();
        for (int n = 0; n < choices.size(); n++) {
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
    else {
        scene[0].Display(scene);
    }
}