#include "Game.h"
Game::Game(int max){
    Game::maxNumber= max;
}
Game::~Game(){
}
void Game::play(){
    Game::randomNumber= std::rand() % Game::maxNumber+1;
    Game::numOfGuesses=1;
std::cout << "Arvaa luku välillä 1-"<< Game::maxNumber << std::endl;

Game::playerGuess;
    do {
        std::cout << "Arvaa luku: ";
        std::cin >> Game::playerGuess;
        if (Game::playerGuess<Game::randomNumber ) {
            std::cout << "Luku on suurempi." << std::endl;
        } else if (Game::playerGuess> Game::randomNumber) {
            std::cout << "Luku on pienempi." << std::endl;
        } else {
            std::cout << "Oikea vastaus!" << std::endl;
            break;
        }
        Game::numOfGuesses++;
    } while (true);
    std::cout << "arvauksien määrä: " << Game::numOfGuesses << std::endl;
}
