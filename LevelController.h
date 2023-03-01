#pragma once
#ifndef LevelController_h
#define LevelController_h
using namespace std;
typedef char* charArrayPtr;
#include <string>
#include <fstream>
#include <iostream>

class LevelController{
public:
    LevelController();
    charArrayPtr* getLevel();
    int level;
    int getLevelNumber();
    void incrementLevel();


private:
    charArrayPtr* levelOne;
    charArrayPtr* levelTwo;
    charArrayPtr* levelThree;
    void setLevel(int);

};

#endif

