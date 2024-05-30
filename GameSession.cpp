#include "GameSession.h"

#include "Game.h"       // Клас Game для управління процесом гри
#include "Fileoutput.h" // Клас для запису у файл
#include "GameMode.h"   // Клас GameMode для вибору режиму гри та розподілу ролей між гравцями
#include "Helper.h"     // Клас з допоміжними функціями
#include <iomanip>      // для маніпуляторів, для красоти

// Гра поле чудес
void GameSession::initSession()
{
    GameMode gameMode;
    ofstream myfile;
    Fileoutput file = Fileoutput("lastSession.txt");

    // Вітання та пояснення гри
    cout << right << setw(66) << "Вітаємо на грі Поле-чудес!" << endl;

    string player1, player2;

    // Виклик методу selectMode для вибору режиму гри та визначення імен гравців
    gameMode.selectMode(player1, player2);

    while (true)
    {
        Game game;

        cout << endl;
        // Отримання від гравця 1 бажання вводити слово приховано
        bool hide = Helper::getYesNoAnswer(player1 + " чи бажаєте ви ввести слово приховано? ");
        string input;

        // Введення слова.
        if (hide)
        {
            cout << player1 << " загадайте слово: " << "\033[32m";
            cin.ignore();
            Helper::hideInput(input);
            cout << "\033[0m" << endl;
        }
        else
        {
            cout << player1 << " загадайте слово: " << "\033[32m";
            cin.ignore();
            getline(cin, input);
            cout << "\033[0m" << endl;
        }

        game.initWord(input);

        // Введіть обмеження спроб та часу гри, якщо гравець 1 погодився
        bool isLimit = Helper::getYesNoAnswer(player1 + ", чи бажаєте встановити обмеження спроб та часу гри? ");
        if (isLimit)
        {
            cout << "Введіть максимальну кількість спроб: " << "\033[32m";
            int attemptsLimit;
            cin >> attemptsLimit;
            cout << "\033[0m";
            game.setAttemptsLimit(attemptsLimit);

            cout << "Введіть максимальний час гри у секундах: " << "\033[32m";
            int timeLimit;
            cin >> timeLimit;
            cout << "\033[0m";

            game.setTimeLimit(timeLimit);
        }
        cout << endl;

        // Початок таймера
        time_t startTime = time(0);

        while (true)
        {
            cout << "\t";
            game.showWord(); // Відображення поточного стану слова
            cout << endl;
            cout << player2 << ", вгадайте букву: " << "\033[32m";
            string guess;
            cin >> guess;
            cout << "\033[0m";

            if (!game.guessLetter(guess))
            { // Перевірка правильності вгадування
                cout << "Неправильно!" << endl;
            }

            if (game.isWordGuessed())
            { // Перевірка, чи вгадано все слово
                // Кінець таймера
                time_t endTime = time(0);
                double duration = difftime(endTime, startTime);

                cout << "Вітаємо! Ви вгадали слово: ";
                game.showWord();
                cout << "Час, витрачений на вгадування: " << fixed << setprecision(2) << "\033[34m" << duration << "\033[0m" << " секунд." << endl
                     << endl;

                file.gameToFile(game, player1, player2, duration);

                break;
            }

            cout << "Спроби: " << "\033[34m" << game.getAttempts() << "\033[0m" << endl
                 << endl; // Відображення кількості спроб

            if (isLimit && (game.attemptsExceeded(game.getAttempts()) || game.timeExceeded(startTime)))
            {
                cout << "Гравець 2, час вичерпано або вичерпано обмеження спроб, загадане слово: \033[34m" << input << "\033[0m" << endl
                     << endl;
                file.gameToFile(player1, player2, input);
                break;
            }
        }

        // Перевірка, чи хочуть грати ще
        if (Helper::getYesNoAnswer("Зіграємо ще? "))
        {
            if (Helper::getYesNoAnswer("Бажаєте змінити режим? "))
            {
                cout << endl;
                gameMode.selectMode(player1, player2);
            }

            else
            {
                gameMode.swapQuestion(player1, player2);
            }
        }
        else
        {
            break;
        }
    }
}