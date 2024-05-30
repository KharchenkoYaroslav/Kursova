#ifndef Game_H
#define Game_H

#include <iostream>
using namespace std;

#include "Letter.h"     // Клас Letter для зберігання букви та її видимості
#include "Limitation.h" // Клас Limitation для встановлення обмежень на спроби та час
#include <List>         // для списку букв, прибажанні можна замінити на щось інше, головне щоб працювало
#include <fstream>      // для запису в файл

class Game
{
private:
    list<Letter> word; // Список букв слова
    int attempts;      // Кількість спроб
    Limitation limit;  // Об'єкт класу Limitation для обмежень гри

public:
    // Конструктор ініціалізації гри з нульовою кількістю спроб
    Game();

    // Метод для встановлення обмеження спроб
    void setAttemptsLimit(int limit);

    // Метод для встановлення обмеження часу гри
    void setTimeLimit(int limitInSeconds);

    // Перевірка перевищення кількості спроб
    bool attemptsExceeded(int attempts);

    // Перевірка перевищення відведеного часу
    bool timeExceeded(time_t startTime);

    // Ініціалізує слово для гри, розділяючи його на букви
    void initWord(string input);

    // Виводить поточний стан слова з відкритими і прихованими буквами
    void showWord();

    // Виводить слово в файл
    void wordToFile(ofstream &file);

    // Обробляє вгадування букви і повертає true, якщо буква присутня у слові
    bool guessLetter(string guess);

    // Перевіряє, чи всі букви слова були вгадані
    bool isWordGuessed();

    // Повертає кількість зроблених спроб
    int getAttempts();
};

#endif