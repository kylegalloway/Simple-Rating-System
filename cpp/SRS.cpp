#include <iostream>
#include <string>
#include <time>
#include "StanfordCPPLib/basicgraph.h"
#include "includes/file_io"
using namespace std;

int main(int argc, char *argv[])
{
    /* Grab Filename */
    if(argc != 2) {
        printf("Usage: %s <input filename>\n", argv[0]);
        exit(1);
    }

    /* Make a new graph */
    Graph G = new BasicGraph();

    /* Read in a file */
    FileIO file = new FileIO(argv[1]);

    /* Add the contents of the file to the graph. (Change to local) */
    G.buildGraph(file);
    cout << "\n";

    /* Rate the teams in the graph. (Change to local) */
    G.rateTeams();
    cout << "\n";

    /*
        Get the list of vertexes
        Can be done much more easily using the new basicgraph.h
    */
    Dict teams = G.getTeams();

    /* Get the team names (Possibly unneeded due to better Dict in C++ */
    string[] teamNames = G.getTeamNames();

    /* print the ratings to the output */
    file.printRatings(teamNames,teams);
    cout << "\n";

    return 0;
}