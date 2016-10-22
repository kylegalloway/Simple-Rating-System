#pragma once

#include <string>
using namespace std;

class Game
{
public:
    Game(string team2, int scoreDiff, Game *next = NULL);
    string getTeam2Name(void);
    int getScoreDiff(void);
    Game getNext();

private:
    Game *next;
    string team2;
    int scoreDiff;
};
