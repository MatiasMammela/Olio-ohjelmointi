#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
class Game{
public:
    ~Game();
    Game(int max);
    void play();
private:
    void printGameResult();
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;
    

};



