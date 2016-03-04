#include <string>
#include "includes/team"
#include "includes/adj_list"
#include "includes/borie_rating_algorithm"
using namespace std;

class Graph
{
    private:
        /*
            TODO: These aren't right...
            Possibly replace Dict and string[] with std::map<>
        */
        Dict teams;
        string[] array;
        int size;
        RatingAlgorithm algorithm;

    public:
        Graph(void)
        {
            this->teams = {};
            this->array = [];
            this->size = 0;
            this->algorithm = RatingAlgorithm();
        }

        void buildGraph(reader)
        {
            /*
            file = reader.readFile()

            for line in file:
                game = reader.parseLine(line)

            if game:
                scoreDiff1 = eval(game.group(2)) - eval(game.group(4))
                scoreDiff2 = 0 - scoreDiff1
                scoreDiff1 = this.algorithm.improveScores(scoreDiff1)
                scoreDiff2 = this.algorithm.improveScores(scoreDiff2)
                this.fillGraph(game.group(1),game.group(3),scoreDiff1,scoreDiff2)
            */
            print("Done")
        }


        void fillGraph(string team1, string team2, int scoreDiff1, int scoreDiff2)
        {
            if (team1 not in this->teams.keys()) { this->addTeam(team1); }
            this->addGame(team1,team2,scoreDiff1);
            if (team2 not in this->teams.keys()) { this->addTeam(team2); }
            this->addGame(team2,team1,scoreDiff2);
        }

        void addTeam(Team team)
        {
            A = AdjList();
            A.insertHead(team);
            this->array.append(A);
            this->teams[team] = this->size;
            this->size += 1;
        }

        void addGame(string team1, string team2,int scoreDiff)
        {
            arrayIndex = this.getTeam(team1);
            this->array[arrayIndex].insert(team2,float(scoreDiff));
        }

        int getSize(this) { return this->size; }
        Team getTeam(this,name) { return this->teams[name]; }

        void rateTeams(this)
        {
            println('Calculating Ratings...');
            this->array = this.algorithm.rateTeams(this->array, this->teams);
            println('Done');
        }

        Dict getTeams(this) { return this->teams; }
        string[] getTeamNames(this) { return this->array; }
}