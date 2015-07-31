

class RatingAlgorithm():

    def __init__(self, iterations = 5000):
        self.ITERATION_CONSTANT = 5000

    def improveScores(self,scoreDiff):
        if scoreDiff < 0:
            if scoreDiff > -3: scoreDiff = -3
            elif scoreDiff < -28: scoreDiff = -28
            scoreDiff += -7
        elif scoreDiff > 0:
            if scoreDiff < 3: scoreDiff = 3
            elif scoreDiff > 28: scoreDiff = 28
            scoreDiff += 7
        return scoreDiff

    def rateTeams(self, array, dict):
        for team in range(len(array)):
            place = array[team].head.next
            total, count, W, L, T = 0, 0 ,0 ,0 ,0
            while place != None:
                scoreDiff = place.getScoreDiff()
                if scoreDiff > 0: W += 1
                elif scoreDiff < 0: L += 1
                else: T += 1
                total += scoreDiff
                count += 1
                place = place.next
            avg = total / count
            array[team].head.setPerformance(avg)
            array[team].head.setRating(avg)
            array[team].head.setWins(W)
            array[team].head.setLosses(L)
            array[team].head.setTies(T)
        for i in range(self.ITERATION_CONSTANT):
            for team in range(len(array)):
                place = array[team].head.next
                total, count = 0, 0
                while place != None:
                    team2 = dict[place.getTeam2()]
                    total += array[team2].head.getRating()
                    count += 1
                    place = place.next
                avg = total / count
                array[team].head.setScheduleFactor(avg)
            for team in range(len(array)):
                performance = array[team].head.getPerformance()
                scheduleFactor = array[team].head.getScheduleFactor()
                newRating = performance + scheduleFactor
                array[team].head.setRating(newRating)

        return array