#include "Fileoutput.h"

//Конструктор від ім'я файлу
Fileoutput::Fileoutput(string filename) : counter(1)
{
    file.open(filename);
    if (!file.is_open())
    {
        exit(0);
    }
}
 //Деструктор закриває запис у файл
Fileoutput::~Fileoutput()
{
    file.close();
}
// Функція для запису гри у файл
void Fileoutput::gameToFile(Game game, string &player1, string &player2, double duration)
{
    file << "Гра номер " << counter << ":" << endl;

    file << "Загадував: " << player1 << endl;
    file << "Вгадував: " << player2 << endl;

    file << "Слово: ";
    game.wordToFile(file);

    file << "Час, витрачений на вгадування: " << duration << " секунд." << endl;

    file << "Спроби: " << game.getAttempts() << endl
         << endl;
    counter++;
}
// Функція для запису гри у файл в разі якщо гравець 2 не вклався в обмеження
void Fileoutput::gameToFile(string &player1, string &player2, string word)
{
    file << "Гра номер " << counter << ":" << endl;

    file << "Загадував: " << player1 << endl;
    file << "Вгадував: " << player2 << endl;

    file << "Слово: " << word << endl;

    file << "Гравець " << player2 << " не вклався в обмеження." << endl;

    counter++;
}
