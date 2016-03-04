#ifndef __ADJ_LIST_H_INCLUDED__
#define __ADJ_LIST_H_INCLUDED__

#include <string>
#include "../includes/team.cpp"
#include "../includes/game.cpp"
using namespace std;

class AdjList
{
    private:
        Team *head;
        Game *tail;
        Game *curr;
        int size;

    public:
        AdjList(void);
        int getSize(void);
        void insertHead(string name);
        void insert(string team2, int scoreDiff);
        Team* getHead(void);
        Game* getTail(void);

};

#endif