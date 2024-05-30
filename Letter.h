#ifndef Letter_H
#define Letter_H

#include <iostream>
using namespace std;

class Letter
{
private:
    string symbol;   // Буква
    bool visibility; // Видимість букви

public:
    // Конструктор ініціалізації букви і встановлення видимості як невидима
    Letter(string c);

    // Повертає символ, якщо видимий, інакше - знак зірочка
    string getChar();

    // Повертає сам символ
    string getSymbol();

    // Встановлює видимість букви
    void setVisibility(bool v);

    // Повертає стан видимості букви
    bool isVisible();
};

#endif