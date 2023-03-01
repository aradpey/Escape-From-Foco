#include "MovementController.h"
#include "GameBoard.h"
#include "PlayerStatusController.h"
#include <iostream>
using namespace std;

MovementController::MovementController() {
}

pair<int,int> MovementController::movePlayer(charArrayPtr *gameBoard, pair<int, int> playerPos, PlayerStatusController psc, int lives){
char userInput;
    cin >> userInput;
    if (userInput == 'w')
    {
        if (playerPos.first >= 2)
        {

            return {playerPos.first - 1, playerPos.second};
        }
    }
    else if (userInput == 'a')
    {
        if (playerPos.second >= 2)
        {
            return {playerPos.first, playerPos.second - 1};
        }
    }
    else if (userInput == 's')
    {
        if (playerPos.first <= 7)
        {
            return {playerPos.first + 1, playerPos.second};
        }
    }
    else if (userInput == 'd')
    {
        if (playerPos.second <= 7)
        {
            return {playerPos.first, playerPos.second + 1};
        }
    }
    return playerPos;
}