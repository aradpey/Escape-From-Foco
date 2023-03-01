#include "PlayerStatusController.h"

PlayerStatusController::PlayerStatusController(){
    setLives(5);
    pair<int,int> initialPos = {8,5};
    setPlayer(initialPos);


}

void PlayerStatusController::removeLive(){
    lives = lives-1;
}

void PlayerStatusController::setLives(int livesToSet){
    lives = livesToSet;
}

int PlayerStatusController::getLives(){
    return lives;
}

pair<int,int> PlayerStatusController::getPlayer(){
    return playerPosition;
}

void PlayerStatusController::setPlayer(pair<int, int> aPlayerPosition){
    playerPosition = aPlayerPosition;
}

void PlayerStatusController::resetPlayer(){
    setPlayer({8,5});
}