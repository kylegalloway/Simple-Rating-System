#include <iostream>
#include <string>
// #include "../includes/graph.cpp"
// #include "../includes/adj_list.cpp"
// #include "../includes/borie_rating_algorithm.cpp"
#include "../includes/game.cpp"
#include "../includes/team.cpp"
// #include "../includes/file_io.cpp"
using namespace std;

void gameClassTest(void)
{
    cout << "\n\nTesting the Game Class\n";
    cout << "+-------------------------------------+\n";
    Game *G = new Game("Alabama Crimson Tide", 10);
    cout << "Team2: " << G->getTeam2Name() << "\n";
    cout << "Should be: Alabama Crimson Tide\n";
    cout << "ScoreDiff: " << G->getScoreDiff() << "\n";
    cout << "Should be: 10\n";
    cout << "+-------------------------------------+\n\n";
}

void teamClassTest(void)
{
    cout << "\n\nTesting the Team Class\n";
    cout << "+-------------------------------------+\n";
    Team *T = new Team("Alabama Crimson Tide");
    cout << "Team: " << T->getName() << "\n";
    cout << "Rating: " << T->getRating() << "\n";
    cout << "Performance: " << T->getPerformance() << "\n";
    cout << "ScheduleFactor: " << T->getScheduleFactor() << "\n";
    cout << "Wins: " << T->getWins() << "\n";
    cout << "Losses: " << T->getLosses() << "\n";
    cout << "Ties: " << T->getTies() << "\n";
    T->setRating(97.6);
    cout << "Rating: " << T->getRating() << "\n";
    cout << "Should be: 97.6\n";
    T->setPerformance(97.6);
    cout << "Performance: " << T->getPerformance() << "\n";
    cout << "Should be: 97.6\n";
    T->setScheduleFactor(97.6);
    cout << "ScheduleFactor: " << T->getScheduleFactor() << "\n";
    cout << "Should be: 97.6\n";
    T->setWins(14);
    cout << "Wins: " << T->getWins() << "\n";
    cout << "Should be: 14\n";
    T->setLosses(1);
    cout << "Losses: " << T->getLosses() << "\n";
    cout << "Should be: 1\n";
    T->setTies(0);
    cout << "Ties: " << T->getTies() << "\n";
    cout << "Should be: 0\n";
    cout << "+-------------------------------------+\n\n";
}

/*
    TODO: Find a way to make Team and Game be the same for the purposes of
    this adj_list. When assigning a list with only 1 Team, can't add games.
*/
// void adjListTest(void)
// {
    // cout << "\n\nTesting the Adjacency List Class\n";
    // cout << "+-------------------------------------+\n";
    // AdjList *A = new AdjList();
    // cout << "Size: " << A->getSize() << "\n";
    // cout << "Should be: 0\n";
    // A->insertHead("Alabama Crimson Tide");
    // cout << "Team: " << A->getHead()->getName() << "\n";
    // cout << "Should be: Alabama Crimson Tide\n";
    // cout << "Size: " << A->getSize() << "\n";
    // cout << "Should be: 1\n";
    // A->insert("Auburn Tigers", 42);
    // Game *G = A->getTail();
    // cout << "Game: " << G->getTeam2Name() << "\n";
    // cout << "Should be: Auburn Tigers\n";
    // cout << "Score: " << G->getScoreDiff() << "\n";
    // cout << "Should be: 42\n";
    // cout << "Size: " << A->getSize() << "\n";
    // cout << "Should be: 2\n";
    // cout << "+-------------------------------------+\n\n";
// }

int main(int argc, char *argv[])
{
    gameClassTest();
    teamClassTest();
    // adjListTest();

    cout << "\n\nAll tests seem to have passed!\n\n";
    return 0;
}