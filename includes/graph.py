from includes.team import Team
from includes.adj_list import AdjList
from includes.rating_algorithm import RatingAlgorithm

class Graph():

    def __init__(self):
        self._teams = {}
        self._array = []
        self._size = 0
        algorithm = RatingAlgorithm()

    def buildGraph(self, reader):
        file = reader.readFile()

        for line in file:
            game = reader.parseLine(line)

        if game:
            scoreDiff1 = eval(game.group(awayScore)) - eval(game.group(homeScore))
            scoreDiff2 = 0 - scoreDiff1
            scoreDiff1 = algorithm.improveScores(scoreDiff1)
            scoreDiff2 = algorithm.improveScores(scoreDiff2)
            self.fillGraph(game.group(awayTeam),game.group(homeTeam),scoreDiff1,scoreDiff2)
        print("Done")


    def fillGraph(self,team1,team2,scoreDiff1,scoreDiff2):
        if team1 not in self._teams.keys(): self.addTeam(team1)
        self.addGame(team1,team2,scoreDiff1)
        if team2 not in self._teams.keys(): self.addTeam(team2)
        self.addGame(team2,team1,scoreDiff2)

    def addTeam(self,team):
        A = AdjList()
        A.insertHead(team)
        self._array.append(A)
        self._teams[team] = self._size
        self._size += 1

    def addGame(self,team1,team2,scoreDiff):
        arrayIndex = self.getTeam(team1)
        self._array[arrayIndex].insert(team2,float(scoreDiff))

    def getSize(self): return self._size
    def getTeam(self,name): return self._teams[name]

    def rateTeams(self):
        print('Calculating Ratings...')
        self._array = self.algorithm.rateTeams(self._array, self._teams)
        print('Done')

    def getTeams(self): return self._teams
    def getTeamNames(self): return self._array