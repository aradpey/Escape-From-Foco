#include "GameBoard.h"
#include "LevelController.h"
#include "PlayerStatusController.h"
#include "MovementController.h"
#include "ScoreController.h"
#include "NPCController.h"
#include <iostream>
using namespace std;

void GameBoard::showGameBoard(charArrayPtr* levelMap, PlayerStatusController psc) {
    int i, j;
	cout << "\n";
    cout << "Lives: " << psc.getLives() << endl;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			cout << levelMap[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}

void GameBoard::levelIntermision(int level){
    if (level > 1){
        int i, j;
        cout << "\n\n";
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 10; j++)
                cout << " - ";
            cout << endl;
        }
        cout << "\t Level " << level - 1 << " Passed \n";
        cout << "\t Starting Level " << level<< "\n";
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 10; j++)
                cout << " - ";
            cout << endl;
        }
        cout << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

void GameBoard::gameOver(float score, float highScore){
    int i, j;
	cout << "\n\n";
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 10; j++)
			cout << " - ";
		cout << endl;
	}
    cout << "\t Game Won!" << endl;
    cout << "\t Score: " <<  score << endl;
    cout << "\t High Score: " << highScore << endl;
    for (i = 0; i < 3; i++) {
		for (j = 0; j < 10; j++)
			cout << " - ";
		cout << endl;
	}
	cout << endl;
}

GameBoard::GameBoard(){
    // Create the Game Board array
    LevelController lc = LevelController();
    PlayerStatusController psc = PlayerStatusController();
    ScoreController sc = ScoreController(); // start tracking the score
    MovementController mc = MovementController();
    gameBoard = lc.getLevel(); // Returns level map

    int level = lc.getLevelNumber();
    pair<int,int> initalPos = psc.getPlayer();
    gameBoard[initalPos.first][initalPos.second] = 'O';
    
    // Initialize NPC's
    NPCController npcOne = NPCController("bob", {6,2}, 0);
    NPCController npcTwo = NPCController("steve", {4,5}, 0);
    NPCController npcThree = NPCController("john", {2,3}, 2);

    NPCController npcFour = NPCController("bob", {4,3}, 2);
    NPCController npcFive = NPCController("steve", {5,5}, 0);
    NPCController npcSix = NPCController("john", {2,6}, 2);
    NPCController npcSeven = NPCController("allen", {6,2}, 0);
    
    NPCController npcEight = NPCController("bob", {7,7}, 0);
    NPCController npcNine = NPCController("steve", {5,5}, 0);
    NPCController npcTen = NPCController("john", {4,2}, 0);
    NPCController npcEleven = NPCController("allen", {3,7}, 0);
    NPCController npcTwelve = NPCController("jason", {6,4}, 0);
    NPCController npcThirteen = NPCController("tatum", {3,4}, 0);

    bool levelStart = true;

    while (psc.getLives() > 0){
        if (levelStart){
            if (lc.getLevelNumber() <= 3){
                levelIntermision(lc.getLevelNumber());
            } 
            if (lc.getLevelNumber() == 1){
                gameBoard[npcOne.getPos().first][npcOne.getPos().second] = 'X';
                gameBoard[npcTwo.getPos().first][npcTwo.getPos().second] = 'X';
                gameBoard[npcThree.getPos().first][npcThree.getPos().second] = 'X';
            } else if (lc.getLevelNumber() == 2){
                gameBoard[npcFour.getPos().first][npcFour.getPos().second] = 'X';
                gameBoard[npcFive.getPos().first][npcFive.getPos().second] = 'X';
                gameBoard[npcSix.getPos().first][npcSix.getPos().second] = 'X';
                gameBoard[npcSeven.getPos().first][npcSeven.getPos().second] = 'X';
            } else if (lc.getLevelNumber() == 3){
                gameBoard[npcEight.getPos().first][npcEight.getPos().second] = 'X';
                gameBoard[npcNine.getPos().first][npcNine.getPos().second] = 'X';
                gameBoard[npcTen.getPos().first][npcTen.getPos().second] = 'X';
                gameBoard[npcEleven.getPos().first][npcEleven.getPos().second] = 'X';
                gameBoard[npcTwelve.getPos().first][npcTwelve.getPos().second] = 'X';
                gameBoard[npcThirteen.getPos().first][npcThirteen.getPos().second] = 'X';

            }
            levelStart = false;
        }
        showGameBoard(gameBoard, psc);
        pair<int,int> playerPos = psc.getPlayer();
        pair<int,int> newPos = mc.movePlayer(gameBoard, playerPos, psc, psc.getLives() );
        psc.setPlayer(newPos);

        if (lc.getLevelNumber() == 1){
            pair<int,int> npcOnePos = npcOne.getPos();
            pair<int,int> npcTwoPos = npcTwo.getPos();
            pair<int,int> npcThreePos = npcThree.getPos();
            
            pair<int,int> newNPCOnePos = npcOne.moveNPCpatrol(gameBoard, 'x', npcOne);
            pair<int,int> newNPCTwoPos = npcTwo.moveNPCpatrol(gameBoard, 'x', npcTwo);
            pair<int,int> newNPCThreePos = npcThree.moveNPCpatrol(gameBoard, 'x', npcThree);

            // Check collision
            if (psc.getPlayer() == newNPCOnePos || psc.getPlayer() == newNPCTwoPos || psc.getPlayer() == newNPCThreePos){
                psc.removeLive();
                if (psc.getLives()  == 0){
                    break;
                }
                gameBoard[playerPos.first][playerPos.second] = '#';
                gameBoard[psc.getPlayer().first][psc.getPlayer().second] = 'V';
            } else {
                gameBoard[playerPos.first][playerPos.second] = '#';
                gameBoard[psc.getPlayer().first][psc.getPlayer().second] = 'O';
            }

            gameBoard[npcOnePos.first][npcOnePos.second] = '#';
            gameBoard[npcTwoPos.first][npcTwoPos.second] = '#';
            gameBoard[npcThreePos.first][npcThreePos.second] = '#';
            
            gameBoard[newNPCOnePos.first][newNPCOnePos.second] = 'X';
            gameBoard[newNPCTwoPos.first][newNPCTwoPos.second] = 'X';
            gameBoard[newNPCThreePos.first][newNPCThreePos.second] = 'X';
        }

        if (lc.getLevelNumber() == 2){
            pair<int,int> npcFourPos = npcFour.getPos();
            pair<int,int> npcFivePos = npcFive.getPos();
            pair<int,int> npcSixPos = npcSix.getPos();
            pair<int,int> npcSevenPos = npcSeven.getPos();
            
            pair<int,int> newNPCFourPos = npcFour.moveNPCpatrol(gameBoard, 'x', npcFour);
            pair<int,int> newNPCFivePos = npcFive.moveNPCpatrol(gameBoard, 'y', npcFive);
            pair<int,int> newNPCSixPos = npcSix.moveNPCpatrol(gameBoard, 'x', npcSix);
            pair<int,int> newNPCSevenPos = npcSeven.moveNPCpatrol(gameBoard, 'y', npcSeven);

            gameBoard[npcFourPos.first][npcFourPos.second] = '^';
            gameBoard[npcFivePos.first][npcFivePos.second] = '^';
            gameBoard[npcSixPos.first][npcSixPos.second] = '^';
            gameBoard[npcSevenPos.first][npcSevenPos.second] = '^';

            gameBoard[newNPCFourPos.first][newNPCFourPos.second] = 'X';
            gameBoard[newNPCFivePos.first][newNPCFivePos.second] = 'X';
            gameBoard[newNPCSixPos.first][newNPCSixPos.second] = 'X';
            gameBoard[newNPCSevenPos.first][newNPCSevenPos.second] = 'X';

            // Check collision
            if (psc.getPlayer() == newNPCFourPos || psc.getPlayer() == newNPCFivePos || psc.getPlayer() == newNPCSixPos ||psc.getPlayer() == newNPCSevenPos){
                psc.removeLive();
                if (psc.getLives()  == 0){
                    break;
                }
                gameBoard[playerPos.first][playerPos.second] = '^';
                gameBoard[psc.getPlayer().first][psc.getPlayer().second] = 'V';
            } else {
                gameBoard[playerPos.first][playerPos.second] = '^';
                gameBoard[psc.getPlayer().first][psc.getPlayer().second] = 'O';
            }
        }

        if (lc.getLevelNumber() == 3){
            pair<int,int> npcEightPos = npcEight.getPos();
            pair<int,int> npcNinePos = npcNine.getPos();
            pair<int,int> npcTenPos = npcTen.getPos();
            pair<int,int> npcElevenPos = npcEleven.getPos();
            pair<int,int> npcTwelvePos = npcTwelve.getPos();
            pair<int,int> npcThirteenPos = npcThirteen.getPos();
            
            pair<int,int> newNPCEightPos = npcEight.moveNPCrand(gameBoard, npcEight);
            pair<int,int> newNPCNinePos = npcNine.moveNPCrand(gameBoard, npcNine);
            pair<int,int> newNPCTenPos = npcTen.moveNPCrand(gameBoard, npcTen);
            pair<int,int> newNPCElevenPos = npcEleven.moveNPCrand(gameBoard, npcEleven);
            pair<int,int> newNPCTwelvePos = npcTwelve.moveNPCrand(gameBoard, npcTwelve);
            pair<int,int> newNPCThirteenPos = npcThirteen.moveNPCrand(gameBoard, npcThirteen);

            gameBoard[npcEightPos.first][npcEightPos.second] = '*';
            gameBoard[npcNinePos.first][npcNinePos.second] = '*';
            gameBoard[npcTenPos.first][npcTenPos.second] = '*';
            gameBoard[npcElevenPos.first][npcElevenPos.second] = '*';
            gameBoard[npcTwelvePos.first][npcTwelvePos.second] = '*';
            gameBoard[npcThirteenPos.first][npcThirteenPos.second] = '*';

            gameBoard[newNPCEightPos.first][newNPCEightPos.second] = 'X';
            gameBoard[newNPCNinePos.first][newNPCNinePos.second] = 'X';
            gameBoard[newNPCTenPos.first][newNPCTenPos.second] = 'X';
            gameBoard[newNPCElevenPos.first][newNPCElevenPos.second] = 'X';
            gameBoard[newNPCTwelvePos.first][newNPCTwelvePos.second] = 'X';
            gameBoard[newNPCThirteenPos.first][newNPCThirteenPos.second] = 'X';

            // Check collision
            if (psc.getPlayer() == newNPCEightPos || psc.getPlayer() == newNPCNinePos || psc.getPlayer() == newNPCTenPos ||psc.getPlayer() == newNPCElevenPos ||psc.getPlayer() == newNPCTwelvePos ||psc.getPlayer() == newNPCThirteenPos ){
                psc.removeLive();
                if (psc.getLives()  == 0){
                    break;
                }
                gameBoard[playerPos.first][playerPos.second] = '*';
                gameBoard[psc.getPlayer().first][psc.getPlayer().second] = 'V';
            } else {
                gameBoard[playerPos.first][playerPos.second] = '*';
                gameBoard[psc.getPlayer().first][psc.getPlayer().second] = 'O';
            }
        }

        if (psc.getPlayer().first == 1){ //Beat the level.
            lc.incrementLevel();
            levelStart = true;
            if (lc.getLevelNumber() == 4){
                float highScore = sc.getHighScore();
                if (sc.getScore() < highScore){
                    sc.setHighScore(highScore);
                }
                gameOver(sc.getScore(), sc.getHighScore());
                break;
            }
            psc.resetPlayer();
            gameBoard=lc.getLevel();
            pair<int,int> initalPos = psc.getPlayer();
            gameBoard[initalPos.first][initalPos.second] = 'O';
        } 
    }
}