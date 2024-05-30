#ifndef Limitation_H
#define Limitation_H

#include <iostream>
using namespace std;

#include <ctime>

class Limitation
{
private:
    int maxAttempts; // Максимальна кількість спроб
    int maxTime;     // Максимальний час гри у секундах

public:
    // Конструктор для обмеження спроб та часу гри
    Limitation();

    // Метод для встановлення обмеження спроб
    void setMaxAttempts(int attempts);

    // Метод для встановлення обмеження часу гри
    void setMaxTime(int time);

    // Перевірка, чи перевищено обмеження спроб
    bool attemptsExceeded(int attempts);
    // Перевірка, чи перевищено обмеження часу гри
    bool timeExceeded(time_t startTime);
};

#endif