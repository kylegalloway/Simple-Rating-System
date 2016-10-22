#include "game.h"

Game::Game(string team2, int scoreDiff, Game *next)
{
    this->team2 = team2;
    this->scoreDiff = scoreDiff;
    this->next = next;
}

string Game::getTeam2Name(void) { return this->team2; }
int Game::getScoreDiff(void) { return this->scoreDiff; }