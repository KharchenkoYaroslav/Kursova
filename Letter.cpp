#include "Letter.h"

Letter::Letter(string c) : symbol(c)
{
    if (c.size() == 2 || isalpha(c[0]))
    { // Якщо символ алфавітний то він приховується
        visibility = false;
    }
    else
    {
        visibility = true;
    }
}

// Повертає символ, якщо видимий, інакше - знак зірочка
string Letter::getChar()
{
    return visibility ? symbol : "*";
}

// Повертає сам символ
string Letter::getSymbol()
{
    return symbol;
}

// Встановлює видимість букви
void Letter::setVisibility(bool v)
{
    visibility = v;
}

// Повертає стан видимості букви
bool Letter::isVisible()
{
    return visibility;
}
