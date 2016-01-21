class Team():

    def __init__(self,name,next = None):
        self._name = name
        self._rating, self._performance, self._scheduleFactor = 0.0, 0.0, 0.0
        self._wins, self._losses, self._ties = 0, 0, 0
        self.next = next

    def getTeam(self): return self._name

    def getRating(self): return float(self._rating)
    def getPerformance(self): return self._performance
    def getScheduleFactor(self): return float(self._scheduleFactor)
    def getWins(self): return int(self._wins)
    def getLosses(self): return int(self._losses)
    def getTies(self): return int(self._ties)

    def setRating(self, rating): self._rating = rating
    def setPerformance(self, performance): self._performance = performance
    def setScheduleFactor(self, factor): self._scheduleFactor = factor
    def setWins(self, wins): self._wins = wins
    def setLosses(self, losses): self._losses = losses
    def setTies(self, ties): self._ties = ties