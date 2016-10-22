#pragma once

#include <string>
using namespace std;

namespace
{
const int ITERATIONS = 5000;
}

class RatingAlgorithm
{
public:
    int improveScores(int scoreDiff);
    string[] rateTeams(string[] array, Dict dict);
};
