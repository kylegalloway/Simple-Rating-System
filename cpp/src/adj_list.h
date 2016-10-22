#pragma once

#include <string>
#include "team.h"
#include "game.h"
using namespace std;

class AdjList
{
public:
    AdjList();
    int getSize();
    void insertHead(string name);
    void insert(string team2, int scoreDiff);
    Team* getHead();
    Game* getTail();

private:
    Team* head_;
    Game* tail_;
    Game* curr_;
    int size_;
};

