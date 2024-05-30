#ifndef Fileoutput_H
#define Fileoutput_H

#include <iostream>
using namespace std;

#include "Game.h"   // Клас Game для управління процесом гри   
#include <fstream>  // для запису в файл

class Fileoutput
{
private:
    ofstream file;
    int counter;

public:
    //Конструктор від ім'я файлу
    Fileoutput(string filename);
    //Деструктор закриває запис у файл
    ~Fileoutput();
    // Функція для запису гри у файл
    void gameToFile(Game game, string &player1, string &player2, double duration);
    // Функція для запису гри у файл в разі якщо гравець 2 не вклався в обмеження
    void gameToFile(string &player1, string &player2, string word);
};

#endif