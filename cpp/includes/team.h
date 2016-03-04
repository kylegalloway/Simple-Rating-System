#ifndef __TEAM_H_INCLUDED__
#define __TEAM_H_INCLUDED__

#include <string>
using namespace std;

class Team
{
    private:
        string name;
        double rating;
        double performance;
        double scheduleFactor;
        int wins;
        int losses;
        int ties;
        string next;

    public:
        Team(string name, string next = "");
        string getName(void);
        double getRating(void);
        double getPerformance(void);
        double getScheduleFactor(void);
        int getWins(void);
        int getLosses(void);
        int getTies(void);
        void setRating(double rating);
        void setPerformance(double performance);
        void setScheduleFactor(double factor);
        void setWins(int wins);
        void setLosses(int losses);
        void setTies(int ties);
};

#endif