#ifndef Helper_H
#define helper_H

#include <iostream>
using namespace std;

class Helper
{
public:
    // Функція для прихованого введення слова (без відображення введених символів)
    static void hideInput(string &word);

    // Функція для отримання відповіді так/ні
    static bool getYesNoAnswer(string prompt);

    // функція для перевірки чи є string українським символом
    static bool findUkr(const string& input);

    //Загальна функція для приведення до нижнього регістру
    static string toLowerLatter(const string& input);
};

#endif