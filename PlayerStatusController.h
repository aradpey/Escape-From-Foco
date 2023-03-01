#pragma once
#ifndef PlayerStatusController_h
#define PlayerStatusController_h
using namespace std;
#include <string>

class PlayerStatusController{
public:
    PlayerStatusController();
    int lives;
    pair<int,int> playerPosition;
    int getLives();
    pair<int,int> getPlayer();
    void setPlayer(pair<int,int>);
    void resetPlayer();
    void removeLive();


private:
    void setLives(int);
    

};

#endif