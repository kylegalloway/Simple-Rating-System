#pragma once

#include <string>
#include "team.h"
/* #include "../includes/team.cpp" */
#include "game.h"
/* #include "../includes/game.cpp" */
using namespace std;

class AdjList
{
public:
    AdjList(void);
    int getSize(void);
    void insertHead(string name);
    void insert(string team2, int scoreDiff);
    Team* getHead(void);
    Game* getTail(void);

private:
    Team *head;
    Game *tail;
    Game *curr;
    int size;
};

