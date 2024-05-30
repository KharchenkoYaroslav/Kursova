#include "Game.h"

#include "Helper.h"    // Клас з допоміжними функціями

// Конструктор ініціалізації гри з нульовою кількістю спроб
Game::Game() : attempts(0) {}

// Метод для встановлення обмеження спроб
void Game::setAttemptsLimit(int limit)
{
    this->limit.setMaxAttempts(limit);
}

// Метод для встановлення обмеження часу гри
void Game::setTimeLimit(int limitInSeconds)
{
    this->limit.setMaxTime(limitInSeconds);
}

// Перевірка перевищення кількості спроб
bool Game::attemptsExceeded(int attempts)
{
    return limit.attemptsExceeded(attempts);
}

// Перевірка перевищення відведеного часу
bool Game::timeExceeded(time_t startTime)
{
    return limit.timeExceeded(startTime);
}

// Ініціалізує слово для гри, розділяючи його на букви
void Game::initWord(string input)
{
    word.clear();
    for (size_t i = 0; i < input.size(); i++)
    {
        string currentChar = string(1, input[i]);
        if (i + 1 < input.size())
        {
            string nextChar = string(1, input[i + 1]);
            string combinedChar = currentChar + nextChar;
            if (Helper::findUkr(combinedChar))
            {
                word.push_back(Letter(combinedChar));
                i++;
            }
            else
            {
                word.push_back(Letter(currentChar));
            }
        }
        else
        {
            word.push_back(Letter(currentChar));
        }
    }
}

// Виводить поточний стан слова з відкритими і прихованими буквами
void Game::showWord()
{
    cout << "\033[34m";
    for (Letter &value : word)
    {
        cout << value.getChar();
    }
    cout << "\033[0m" << endl;
}

// Виводить слово в файл
void Game::wordToFile(ofstream &file)
{
    for (Letter &value : word)
    {
        file << value.getChar();
    }
    file << endl;
}

// Обробляє вгадування букви і повертає true, якщо буква присутня у слові
bool Game::guessLetter(string guess)
{
    bool guessedCorrectly = false;
    for (Letter &l : word)
    {
        if (Helper::toLowerLatter(l.getSymbol()) == Helper::toLowerLatter(guess))
        {
            l.setVisibility(true);
            guessedCorrectly = true;
        }
    }
    attempts++;
    return guessedCorrectly;
}

// Перевіряє, чи всі букви слова були вгадані
bool Game::isWordGuessed()
{
    for (Letter &l : word)
    {
        if (!l.isVisible())
        {
            return false;
        }
    }
    return true;
}

// Повертає кількість зроблених спроб
int Game::getAttempts()
{
    return attempts;
}
