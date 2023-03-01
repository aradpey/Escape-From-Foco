#pragma once
#ifndef GameBoard_h
#define GameBoard_h
using namespace std;
#include <string>
#include "PlayerStatusController.h"
#include <chrono>
#include <thread>
typedef char* charArrayPtr;

class GameBoard{
public: 
    GameBoard();
    void showGameBoard(charArrayPtr*, PlayerStatusController);
private:
    void levelIntermision(int);
    void gameOver(float, float);
    charArrayPtr* gameBoard;

};

#endif