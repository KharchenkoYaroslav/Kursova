#include "Helper.h"

#include <termios.h>    // Для прихованого вводу слова
#include <unistd.h>     // Для прихованого вводу слова
#include <algorithm>    // Для пошуку букви в масиві

// Функція для прихованого введення слова (без відображення введених символів)
void Helper::hideInput(string &word)
{
    termios old;
    tcgetattr(STDIN_FILENO, &old);
    termios hide = old;
    hide.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &hide);
    getline(cin, word);
    cout << endl;
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
}

// Функція для отримання відповіді так/ні
bool Helper::getYesNoAnswer(string prompt)
{
    string answer;
    while (true)
    {
        cout << prompt << "\033[32m";
        cin >> answer;
        if (answer == "Yes" || answer == "yes" || answer == "Так" || answer == "так")
        {
            cout << "\033[0m";
            return true;
        }
        else if (answer == "No" || answer == "no" || answer == "Ні" || answer == "ні")
        {
            cout << "\033[0m";
            return false;
        }
        else
        {
            cout << "\033[0m" << "Неправильний формат відповіді. Введіть 'Yes/Так' або 'No/Ні'." << endl;
        }
    }
}

// функція для перевірки чи є string українським символом
bool Helper::findUkr(const string &input)
{
    // Массиви з українськими літерами для перевірки складових букв
    string ukrAlphaLow[] = {"а", "б", "в", "г", "ґ", "д", "е", "є", "ж", "з", "и", "і", "ї", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ь", "ю", "я"};
    string ukrAlphaUp[] = {"А", "Б", "В", "Г", "Ґ", "Д", "Е", "Є", "Ж", "З", "И", "І", "Ї", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ь", "Ю", "Я"};

    return (find(begin(ukrAlphaLow), end(ukrAlphaLow), input) != end(ukrAlphaLow) || find(begin(ukrAlphaUp), end(ukrAlphaUp), input) != end(ukrAlphaUp));
}

// Загальна функція для приведення до нижнього регістру
string Helper::toLowerLatter(const string &input)
{
    if (input.empty())
        return input;

    if (isalpha(input[0]))
    {
        return string(1, tolower(input[0]));
    }

    string combinedChar = input.substr(0, 2);
    if (findUkr(combinedChar))
    {
        string ukrAlphaLow[] = {"а", "б", "в", "г", "ґ", "д", "е", "є", "ж", "з", "и", "і", "ї", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ь", "ю", "я"};
        string ukrAlphaUp[] = {"А", "Б", "В", "Г", "Ґ", "Д", "Е", "Є", "Ж", "З", "И", "І", "Ї", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ь", "Ю", "Я"};

        auto f = find(begin(ukrAlphaUp), end(ukrAlphaUp), combinedChar);
        if (f != end(ukrAlphaUp))
        {
            int index = f - begin(ukrAlphaUp);
            return ukrAlphaLow[index];
        }
    }

    return input;
}
