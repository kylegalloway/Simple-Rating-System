#pragma once

#include <string>
#include "team.h"
#include "adj_list.h"
#include "borie_rating_algorithm.h"
using namespace std;

class Graph
{
public:
    Graph();

    void buildGraph(/* reader */);
    void fillGraph(string team1, string team2,
                   int scoreDiff1, int scoreDiff2);
    void addTeam(Team team);
    void addGame(string team1, string team2,int scoreDiff);

private:
    int getSize();
    Team getTeam(string name);
    void rateTeams();
    Dict getTeams();
    string[] getTeamNames();

private:
    /*
        TODO: Possibly replace Dict and string[] with std::map<>
    */
    Dict teams_;
    string[] array_;
    int size_;
    RatingAlgorithm algorithm_;

