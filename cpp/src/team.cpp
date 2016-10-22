#include "team.h"

Team::Team(string name, string next)
{
    this->name = name;
    this->rating = 0.0;
    this->performance = 0.0;
    this->scheduleFactor = 0.0;
    this->wins = 0;
    this->losses = 0;
    this->ties = 0;
    this->next = next;
}
string Team::getName(void) { return this->name; }
double Team::getRating(void) { return this->rating; }
double Team::getPerformance(void) { return this->performance; }
double Team::getScheduleFactor(void) { return this->scheduleFactor; }
int Team::getWins(void) { return this->wins; }
int Team::getLosses(void) { return this->losses; }
int Team::getTies(void) { return this->ties; }

void Team::setRating(double rating) { this->rating = rating; }
void Team::setPerformance(double performance) { this->performance = performance; }
void Team::setScheduleFactor(double factor) { this->scheduleFactor = factor; }
void Team::setWins(int wins) { this->wins = wins; }
void Team::setLosses(int losses) { this->losses = losses; }
void Team::setTies(int ties) { this->ties = ties; }