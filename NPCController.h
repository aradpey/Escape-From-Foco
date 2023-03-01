#pragma once
#ifndef NPCController_h
#define NPCController_h
using namespace std;
#include <string>
#include <vector>
typedef char* charArrayPtr;

class NPCController {
    public:
    NPCController(); //default constructor

    NPCController(string, pair<int,int>, int);
    //level number input and the name of the NPC within the level, so multiple can be added in one level

    //NPCController(const NPCController&);
    //copy constructor, may not be needed but is added for completeness.
    
    
    pair<int,int> moveNPCrand(charArrayPtr*, NPCController);

    pair<int,int> moveNPCpatrol(charArrayPtr*, char orientation, NPCController);


    pair<int,int> getPos();
    int getDir() const;
    string getName() const;


    private:

        pair<int,int> pos;
        int dir; //Direction it's going: 0 = +x, 1 = +y, 2 = -x, 3 = -y.   To remember this order, think of going around the unit circle in x-y axis.
        string name;
    
};


#endif