#include "NPCController.h"
#include "GameBoard.h"

using namespace std;
typedef char* charArrayPtr;

NPCController::NPCController(){
}

NPCController::NPCController(const string npcName, pair<int,int> position, int aDir){
    name = npcName;
    dir = aDir;
    pos = position;
}

// NPCController::NPCController(const NPCController& orig){
//     pos = orig.getPos();
//     dir = orig.getDir();
//     name = orig.getName();
// }

pair<int,int> NPCController::moveNPCrand(charArrayPtr* levelMap, NPCController npc){
    pair<int,int> newPos = npc.getPos();
    switch(npc.getDir()) {
        case 0: // +x direction, adds one to col count
        if(npc.getPos().second < 8) {
            newPos.second += 1;
        } break;
        
        case 1: // +y direction, removes one from row count
        if(npc.getPos().first > 1){
            newPos.first -= 1;
        } break;

        case 2: // -x direction, removes one from col count.
        if(npc.getPos().second > 1){
            newPos.second -= 1;
        } break;

        case 3: //-y direction, adds one to row count
        if(npc.getPos().first < 8){
            newPos.first += 1;
        }break;
    }
    vector<int> table = {0,1,2,3}; //table for possible directions
    int corner = 0; //flag for if in corner so know to skip secondary assignments

    if(newPos.second == 8){ //right side of grid edge case
        if(newPos.first == 1){ //top right corner
        table = {2,3};
        corner = 1; //flag 
        }else if(newPos.first == 8){ //bottom right corner
        table = {1,3};
        corner = 1;
        }else{
        table = {1,2,3};
        }
    }
    if(newPos.second == 1){ //left side of grid edge case
        if(newPos.first == 1){ //top left corner
        table = {0,3};
        corner = 1;
        }else if(newPos.first == 8){ //bottom left corner
        table = {0,1};
        corner = 1;
        }else{
        table = {0,1,3};
        }
    }

    //already did corner cases, now just top and bottom
    if(newPos.first == 1 && corner == 0){ //top of grid
        table = {0,2,3};
    }
    if(newPos.first == 8 && corner == 0){ //bottom of grid
        table = {0,1,2};
    }

    int index = rand() % (table.size()); //gets a random index for the fixed lookup table

    this->dir = table[index]; //sets the direction of the npc for the next move to a viable random position
    this->pos = newPos;
    return newPos; //returns the new position as a pair
}


pair<int,int> NPCController::moveNPCpatrol(charArrayPtr* levelMap, char orientation, NPCController npc){
    // x or y are viable orientations, will patrol from side to side in its orientation
    pair<int,int> newPos = npc.getPos();
    
    if(orientation == 'x'){
    if(npc.getDir() == 0){
        if(npc.getPos().second < 8){  //  +x
            newPos.second += 1;
        }else{//must be at the right wall
            newPos.second -= 1;
            this->dir = 2; //new direction is -x
        }
    } else if(npc.getDir() == 2){ // -x
        if(npc.getPos().second > 1){  
            newPos.second -= 1;
        }else{//must be at the left wall
            newPos.second += 1;
            this->dir = 0;
        }
    }
    } //end of x-orientation

    if(orientation == 'y'){
        if(npc.getDir() == 1){
        if(npc.getPos().first > 1){  // +y
            newPos.first -= 1; //forwards for this axis is up, meaning (-) on the index
        }else{//must be at the top wall
            newPos.first += 1;
            this->dir = 3;
        }
    } else if(npc.getDir() == 3){ // -y
        if(npc.getPos().first < 8){  //backwards
            newPos.first -= 1;
        }else{//must be at the bottom wall
            newPos.first += 1;
            this->dir = 1;
        }
    }
    } //end of y-orientation
    this->pos = newPos;
    return newPos;
}


pair<int,int> NPCController::getPos(){
    return pos;
}

int NPCController::getDir() const{
    return dir;
}

string NPCController::getName() const{
    return name;
}