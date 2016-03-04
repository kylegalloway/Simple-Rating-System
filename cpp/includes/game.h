#ifndef __GAME_H_INCLUDED__
#define __GAME_H_INCLUDED__

#include <string>
using namespace std;

class Game
{
private:
    string team2;
    int scoreDiff;

public:
    Game *next;

    Game(string team2, int scoreDiff, Game *next = NULL);
    string getTeam2Name(void);
    int getScoreDiff(void);
};

#endif