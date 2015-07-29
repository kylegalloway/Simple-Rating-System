class Graph():

    def __init__(self,filename):
        self._filename = filename
        self._teams = {}
        self._array = []
        self._size = 0


    def buildGraph(self):
        print('Reading File...')
        with open(self._filename, 'r') as f:
            for line in f:
                while line != '':
                    # team1 = line[:33]
                    # score1 = line[33:37]
                    # team2 = line[37:70]
                    # score2 = line[70:]
                    # team1 = team1.strip()
                    # score1 = eval(score1.strip())
                    # team2 = team2.strip()
                    # score2 = eval(score2.strip())
                    processed = self.processLine(line.strip())
                    team1 = processed[0]
                    score1 = processed[1]
                    team2 = processed[2]
                    score2 = processed[3]
                    scoreDiff1 = score1 - score2
                    scoreDiff2 = 0 - scoreDiff1
                    scoreDiff1 = self.improveScores(scoreDiff1)
                    scoreDiff2 = self.improveScores(scoreDiff2)
                    self.fillGraph(team1,team2,scoreDiff1,scoreDiff2)
            print("Done")

    def processLine(self,line):
        newString = ''
        count = 0
        for i in line:
            if count == 0:
                if not i.isdigit():
                    newString += i
                else:
                    team1 = newString
                    newString = ''
                    count += 1
            if count == 1:
                if not i.isalpha():
                    newString += i
                else:
                    score1 = newString
                    newString = ''
                    count += 1
            if count == 2:
                if not i.isdigit():
                    newString += i
                else:
                    team2 = newString
                    newString = ''
                    count += 1
            if count == 3:
                if not i.isalpha():
                    newString += i
                else:
                    score2 = newString
                    newString = ''
                    count += 1

        team1 = team1.strip()
        score1 = eval(score1.strip())
        team2 = team2.strip()
        score2 = eval(score2.strip())

        return [team1,score1,team2,score2]

    def improveScores(self,scoreDiff):
        if scoreDiff < 0:
            if scoreDiff > -3:
                scoreDiff = -3
            elif scoreDiff < -28:
                scoreDiff = -28
            scoreDiff += -7
        elif scoreDiff > 0:
            if scoreDiff < 3:
                scoreDiff = 3
            elif scoreDiff > 28:
                scoreDiff = 28
            scoreDiff += 7
        return scoreDiff


    def fillGraph(self,team1,team2,scoreDiff1,scoreDiff2):
        if team1 not in self._teams.keys():
            self.addTeam(team1)
        self.addGame(team1,team2,scoreDiff1)
        if team2 not in self._teams.keys():
            self.addTeam(team2)
        self.addGame(team2,team1,scoreDiff2)

    def addTeam(self,team):
        A = Adjlist()
        A.insertHead(team)
        self._array.append(A)
        self._teams[team] = self._size
        self._size += 1

    def addGame(self,team1,team2,scoreDiff):
        arrayIndex = self.getTeam(team1)
        self._array[arrayIndex].insert(team2,float(scoreDiff))

    def getSize(self):
        return self._size

    def getTeam(self,name):
        return self._teams[name]

    def rateTeams(self):
        print('Calculating Ratings...')
        for team in range(len(self._array)):
            place = self._array[team].head.next
            total = 0
            count = 0
            W = 0
            L = 0
            T = 0
            while place != None:
                scoreDiff = place.getScoreDiff()
                if scoreDiff > 0:
                    W += 1
                elif scoreDiff < 0:
                    L += 1
                else:
                    T += 1
                total += scoreDiff
                count += 1
                place = place.next
            avg = total / count
            self._array[team].head.setPerformance(avg)
            self._array[team].head.setRating(avg)
            self._array[team].head.setWins(W)
            self._array[team].head.setLosses(L)
            self._array[team].head.setTies(T)
        for i in range(5000):
            for team in range(len(self._array)):
                place = self._array[team].head.next
                total = 0
                count = 0
                while place != None:
                    team2 = self.getTeam(place.getTeam2())
                    total += self._array[team2].head.getRating()
                    count += 1
                    place = place.next
                avg = total / count
                self._array[team].head.setScheduleFactor(avg)
            for team in range(len(self._array)):
                performance = self._array[team].head.getPerformance()
                scheduleFactor = self._array[team].head.getScheduleFactor()
                newRating = performance + scheduleFactor
                self._array[team].head.setRating(newRating)
        print('Done')

    def printRatings(self):
        print("Printing Ratings...")
        newfilename = 'rankings_' + self._filename
        with open(newfilename, 'w') as f:
            spacer = ' ' * (32 - len('Team'))
            f.write(('Rank\tTeam{0}W-L-T\tRating\n').format(spacer))
            count = 1
            lyst = []
            for team in sorted(self._teams.keys(),key=lambda team: self._array[self.getTeam(team)].head.getRating(),reverse=True):
                thisTeam = self.getTeam(team)
                rating = self._array[thisTeam].head.getRating()
                W = self._array[thisTeam].head.getWins()
                L = self._array[thisTeam].head.getLosses()
                T = self._array[thisTeam].head.getTies()
                spacer = ' ' * (32 - len(team))
                f.write(('{0}\t\t{1}{2}{3}-{4}-{5}\t{6}\n').format(count,team,spacer,W,L,T,round(rating,4)))
                count += 1
        newfilename = 'strofsch_' + self._filename
        with open(newfilename, 'w') as f:
            spacer = ' ' * (32 - len('Team'))
            f.write(('Rank\tTeam{0}W-L-T\tSchedule Factor\n').format(spacer))
            count = 1
            lyst = []
            for team in sorted(self._teams.keys(),key=lambda team: self._array[self.getTeam(team)].head.getScheduleFactor(),reverse=True):
                thisTeam = self.getTeam(team)
                schedule_factor = self._array[thisTeam].head.getScheduleFactor()
                W = self._array[thisTeam].head.getWins()
                L = self._array[thisTeam].head.getLosses()
                T = self._array[thisTeam].head.getTies()
                spacer = ' ' * (32 - len(team))
                f.write(('{0}\t\t{1}{2}{3}-{4}-{5}\t{6}\n').format(count,team,spacer,W,L,T,round(schedule_factor,4)))
                count += 1
        print("Done")