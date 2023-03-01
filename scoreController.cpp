#include "ScoreController.h"
using namespace std;


ScoreController::ScoreController(){
    setStart();
}

float ScoreController::getScore(){
    finish = static_cast<int>(time(nullptr));
    return finish - start;
}

float ScoreController::getHighScore(){

    ifstream fin("highscore.txt");

    int score;


    while (fin >> score) {}
    return score;
}

void ScoreController::setHighScore(float score){
    deleteLine("highscore.txt", to_string(getHighScore()));
    ofstream myfile;
    myfile.open ("highscore.txt");
    myfile << getScore();
    myfile.close();
    
}

void ScoreController::deleteLine(string path, string eraseLine) {
    string line;
    ifstream fin;
    
    fin.open(path);
    // contents of path must be copied to a temp file then
    // renamed back to the path file
    ofstream temp;
    temp.open("temp.txt");

    while (getline(fin, line)) {
        // write all lines to temp other than the line marked for erasing
        if (line != eraseLine)
            temp << line << std::endl;
    }

    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    const char * p = path.c_str();
    remove(p);
    rename("temp.txt", p);
}

void ScoreController::setStart(){
    start = static_cast<int>(time(nullptr));
}
