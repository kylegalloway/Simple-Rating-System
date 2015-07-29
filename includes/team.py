class Team():

    def __init__(self,name,next = None):
        self._name = name
        self._rating = 0.0
        self._performance = 0.0
        self._scheduleFactor = 0.0
        self._wins = 0
        self._losses = 0
        self._ties = 0
        self.next = next

    def getTeam(self):
        return self._name

    def getRating(self):
        return float(self._rating)

    def setRating(self, rating):
        self._rating = rating

    def getPerformance(self):
        return self._performance

    def setPerformance(self, performance):
        self._performance = performance

    def getScheduleFactor(self):
        return float(self._scheduleFactor)

    def setScheduleFactor(self, factor):
        self._scheduleFactor = factor

    def getWins(self):
        return int(self._wins)

    def setWins(self, wins):
        self._wins = wins

    def getLosses(self):
        return int(self._losses)

    def setLosses(self, losses):
        self._losses = losses

    def getTies(self):
        return int(self._ties)

    def setTies(self, ties):
        self._ties = ties