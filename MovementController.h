#pragma once
#ifndef MovementController_h
#define MovementController_h
using namespace std;
typedef char* charArrayPtr;
#include <iostream>
#include "PlayerStatusController.h"


class MovementController{
public:
    MovementController();
    pair<int,int> movePlayer(charArrayPtr*, pair<int,int>, PlayerStatusController, int);
};

#endif