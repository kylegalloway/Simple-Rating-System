#pragma once

#include <string>
#include "node.h"
using namespace std;

class Game : public Node
{
public:
    Game(string team2, int scoreDiff, Node *next = NULL);
    string getTeam2Name();
    int getScoreDiff();

    Node next();

private:
    Node *next_;
    string team2_;
    int scoreDiff_;
};
