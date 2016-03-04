#include <iostream>
#include <string>
#include <time>
#include "includes/graph"
#include "includes/file_io"
using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Usage: %s <input filename>\n", argv[0]);
        exit(1);
    }

    Graph G = new Graph();
    FileIO file = new FileIO(argv[1]);
    G.buildGraph(file);
    cout << "\n";
    G.rateTeams();
    cout << "\n";
    Dict teams = G.getTeams();
    string[] teamNames = G.getTeamNames();
    file.printRatings(teamNames,teams);
    cout << "\n";

    return 0;
}