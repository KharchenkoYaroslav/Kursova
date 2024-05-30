#ifndef GameMode_H
#define GameMode_H

#include <iostream>
using namespace std;

class GameMode
{
public:
    // Метод для вибору режиму гри та визначення імен гравців
    void selectMode(string &player1, string &player2);
    // Метод для обміну ролями гравців
    void swapQuestion(string &player1, string &player2);
};

#endif