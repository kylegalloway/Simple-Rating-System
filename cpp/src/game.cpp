#include "game.h"

Game::Game(string team2, int scoreDiff, Game *next)
{
    team2_ = team2;
    scoreDiff_ = scoreDiff;
    next_ = next;
}

string Game::getTeam2Name()
{
    return team2_;
}
int Game::getScoreDiff()
{
    return scoreDiff_;
}

Node Game::next()
{
    return next_;
}
