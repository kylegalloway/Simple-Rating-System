class Game():

    def __init__(self, team2, scoreDiff, next = None):
        self._team2 = team2
        self._scoreDiff = scoreDiff
        self.next = next

    def getTeam2(self): return self._team2
    def getScoreDiff(self): return self._scoreDiff