#include "GameMode.h"   

#include "Helper.h"     // Клас з допоміжними функціями
#include <iomanip>      // для маніпуляторів, для красоти

void GameMode::selectMode(string &player1, string &player2)
{
    // Вивід інструкцій для вибору режиму гри
    cout << right << setw(58) << "Виберіть режим гри " << endl;
    cout << "Режим 1: Ввести імена двох гравців, перший загадує а другий відгадує" << endl;
    cout << "Режим 2: Ввести імена двох гравців, програма випадково розподілить ролі" << endl;

    // Отримання вибору режиму від користувача
    int choice;
    cout << "Який режим хочете обрати? " << "\033[32m";
    cin >> choice;
    cout << "\033[0m";

    if (choice == 2)
    {
        // Введення імен гравців для другого режиму
        cout << "Введіть ім'я гравця 1: " << "\033[32m";
        cin >> player1;
        cout << "\033[0m" << "Введіть ім'я гравця 2: " << "\033[32m";
        cin >> player2;
        cout << "\033[0m";

        // Випадкове розподілення ролей між гравцями
        srand(time(0));
        if (rand() % 2 == 0)
        {
            cout << player1 << " загадує слово, " << player2 << " відгадує." << endl;
        }
        else
        {
            cout << player2 << " загадує слово, " << player1 << " відгадує." << endl;
            swap(player1, player2);
        }
    }
    else
    {
        // Введення імен гравців для другого режиму
        cout << "Введіть ім'я гравця 1: " << "\033[32m";
        cin >> player1;
        cout << "\033[0m" << "Введіть ім'я гравця 2: " << "\033[32m";
        cin >> player2;
        cout << "\033[0m";
    }
}
// Метод для обміну ролями гравців
void GameMode::swapQuestion(string &player1, string &player2)
{
    bool swapQ = Helper::getYesNoAnswer("Бажаєте помінятися? ");
    if (swapQ)
    {
        swap(player1, player2);
    }
}
