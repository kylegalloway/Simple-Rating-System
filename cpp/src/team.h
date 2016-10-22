#pragma once

#include <string>
#include "node.h"
using namespace std;

class Team : public Node
{
public:
    Team(string name, string next = "");
    string getName();
    double getRating();
    double getPerformance();
    double getScheduleFactor();
    int getWins();
    int getLosses();
    int getTies();
    void setRating(double rating);
    void setPerformance(double performance);
    void setScheduleFactor(double factor);
    void setWins(int wins);
    void setLosses(int losses);
    void setTies(int ties);

    Node next();

private:
    string name_;
    double rating_;
    double performance_;
    double scheduleFactor_;
    int wins_;
    int losses_;
    int ties_;
    string next_;
};
