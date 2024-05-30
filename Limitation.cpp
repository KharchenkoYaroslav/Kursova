#include "Limitation.h"

// Конструктор для обмеження спроб та часу гри
Limitation::Limitation() : maxAttempts(0), maxTime(0) {}

// Метод для встановлення обмеження спроб
void Limitation::setMaxAttempts(int attempts)
{
    maxAttempts = attempts;
}

// Метод для встановлення обмеження часу гри
void Limitation::setMaxTime(int time)
{
    maxTime = time;
}

// Перевірка, чи перевищено обмеження спроб
bool Limitation::attemptsExceeded(int attempts)
{
    return attempts > maxAttempts;
}

// Перевірка, чи перевищено обмеження часу гри
bool Limitation::timeExceeded(time_t startTime)
{
    time_t currentTime = time(0);
    double duration = difftime(currentTime, startTime);
    return duration > maxTime;
}
