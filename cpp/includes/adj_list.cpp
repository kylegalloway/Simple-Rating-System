#include "adj_list.h"

AdjList::AdjList(void)
{
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

int AdjList::getSize(void) { return this->size; }

void AdjList::insertHead(string name)
{
    this->tail = this->head;
    this->head = new Team(name);
    if (this->tail == NULL)
        this->tail = this->head;
    this->size += 1;
}

void AdjList::insert(string team2, int scoreDiff)
{
    curr = this->tail;
    curr->next = new Game(team2, scoreDiff);
    this->tail = curr->next;
    this->size += 1;
}

Team* AdjList::getHead(void)
{
    return this->head;
}

Game* AdjList::getTail(void)
{
    return this->tail;
}