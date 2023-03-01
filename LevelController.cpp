#include "LevelController.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

LevelController::LevelController(){
    setLevel(1);

    levelOne = new char* [10];
    for (int i=0; i<10; i++){
        levelOne[i] = new char[10];
    }
    char chOne;
    fstream finOne("level_one.txt", fstream::in);
    int i = 0, j = 0;
    while (finOne >> noskipws >> chOne) {
        levelOne[i][j] = chOne;
        if (j==9){
            j=0;
            i++;
        } else{
            j++;
        }
    }

    levelTwo = new char* [10];
    for (int i=0; i<10; i++){
        levelTwo[i] = new char[10];
    }
    char chTwo;
    fstream finTwo("level_two.txt", fstream::in);
    i = 0, j = 0;
    while (finTwo >> noskipws >> chTwo) {
        levelTwo[i][j] = chTwo;
        if (j==9){
            j=0;
            i++;
        } else{
            j++;
        }
    }

    levelThree = new char* [10];
    for (int i=0; i<10; i++){
        levelThree[i] = new char[10];
    }
    char chThree;
    fstream finThree("level_three.txt", fstream::in);
    i = 0, j = 0;
    while (finThree >> noskipws >> chThree) {
        levelThree[i][j] = chThree;
        if (j==9){
            j=0;
            i++;
        } else{
            j++;
        }
    }
}

void LevelController::setLevel(int aLevel){
    level = aLevel;
}
int LevelController::getLevelNumber(){
    return level;
}

void LevelController::incrementLevel(){
    level++;
}

charArrayPtr* LevelController::getLevel(){
    charArrayPtr* copyLevel = new char*[10];
	for (int i = 0; i < 10; i++)
		copyLevel[i] = new char [10];

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
            if (level == 1){
		        copyLevel[i][j] = levelOne[i][j];
            } else if (level == 2){
                copyLevel[i][j] = levelTwo[i][j];
            } else if (level == 3){
                copyLevel[i][j] = levelThree[i][j];
            }
        }
	}
	return copyLevel;
}
