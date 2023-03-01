#pragma once
#ifndef ScoreController_h
#define ScoreController_h
using namespace std;
#include <ctime>
#include <fstream>
#include <iostream>
#include  <bits/stdc++.h>

class ScoreController{
    public:
        ScoreController();
        int start, finish;
        float getScore();
        void setStart();
        float getHighScore();
        void setHighScore(float);
    private:
        
        void deleteLine(string, string);
};



#endif