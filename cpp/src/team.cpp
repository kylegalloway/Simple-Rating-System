#include "team.h"

Team::Team(string name, string next)
{
    name_ = name;
    rating_ = 0.0;
    performance_ = 0.0;
    scheduleFactor_ = 0.0;
    wins_ = 0;
    losses_ = 0;
    ties_ = 0;
    next_ = next;
}

string Team::getName()
{
    return name_;
}

double Team::getRating()
{
    return rating_;
}

double Team::getPerformance()
{
    return performance_;
}

double Team::getScheduleFactor()
{
    return scheduleFactor_;
}

int Team::getWins()
{
    return wins_;
}

int Team::getLosses()
{
    return losses_;
}

int Team::getTies()
{
    return ties_;
}

void Team::setRating(double rating)
{
    rating_ = rating;
}

void Team::setPerformance(double performance)
{
    performance_ = performance;
}

void Team::setScheduleFactor(double factor)
{
    scheduleFactor_ = factor;
}

void Team::setWins(int wins)
{
    wins_ = wins;
}

void Team::setLosses(int losses)
{
    losses_ = losses;
}

void Team::setTies(int ties)
{
    ties_ = ties;
}

Node Team::next()
{
    return next_;
}
