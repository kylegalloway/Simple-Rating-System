#include "adj_list.h"

AdjList::AdjList()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

int AdjList::getSize()
{
    return size_;
}

void AdjList::insertHead(string name)
{
    tail_ = head_;
    head_ = new Team(name);
    if (tail_ == NULL)
    {
        tail_ = head_;
    }
    size_ += 1;
}

void AdjList::insert(string team2, int scoreDiff)
{
    curr_ = tail_;
    curr_->next() = new Game(team2, scoreDiff);
    tail_ = curr_->next();
    size_ += 1;
}

Team* AdjList::getHead()
{
    return head_;
}

Game* AdjList::getTail()
{
    return tail_;
}
