Graph::Graph()
{
    teams_ = {};
    array_ = [];
    size_ = 0;
    algorithm_ = RatingAlgorithm();
}

void Graph::buildGraph(/* reader */)
{
    /*
    file = reader.readFile()

    for line in file:
        game = reader.parseLine(line)

    if game:
        scoreDiff1 = eval(game.group(2)) - eval(game.group(4))
        scoreDiff2 = 0 - scoreDiff1
        scoreDiff1 = algorithm_.improveScores(scoreDiff1)
        scoreDiff2 = algorithm_.improveScores(scoreDiff2)
        fillGraph(game.group(1),game.group(3),scoreDiff1,scoreDiff2)
    */
    print("Done")
}


void Graph::fillGraph(string team1, string team2, int scoreDiff1, int scoreDiff2)
{
    if (team1 not in teams_.keys())
    {
        addTeam(team1);
    }
    addGame(team1,team2,scoreDiff1);
    if (team2 not in teams_.keys())
    {
        addTeam(team2);
    }
    addGame(team2,team1,scoreDiff2);
}

void Graph::addTeam(Team team)
{
    A = AdjList();
    A.insertHead(team);
    array_.append(A);
    teams_[team] = size_;
    size_ += 1;
}

void Graph::addGame(string team1, string team2,int scoreDiff)
{
    arrayIndex = getTeam(team1);
    array_[arrayIndex].insert(team2,float(scoreDiff));
}

int Graph::getSize()
{
    return size_;
}

Team Graph::getTeam(string name)
{
    return teams_[name];
}

void Graph::rateTeams()
{
    println('Calculating Ratings...');
    array_ = algorithm_.rateTeams(array_, teams_);
    println('Done');
}

Dict Graph::getTeams()
{
    return teams_;
}

string[] Graph::getTeamNames()
{
    return array_;
}
