import re

class FileIO():

    def __init__(self,filename):
        self._inputFilename = filename
        self._outputFilename = re.sub('[a-zA-z0-9]*/*', '', filename)

    def readFile(self):
        print('Reading File...')
        with open(self._inputFilename, 'r') as file:
            return file

    def parseLine(self, line = None):
        if line:
            pattern = re.compile(r'(?P<awayTeam>[^0-9]+)(?P<awayScore>[0-9]+)(?P<homeTeam>[^0-9]+)(?P<homeScore>[0-9]+)')
            game = pattern.search(str(line).strip())

            return game
        return None

    def printRatings(self, array, dict):
        print("Printing Ratings...")
        newfilename = 'output/Ratings/ratings_' + self._outputFilename
        with open(newfilename, 'w') as f:
            spacer = ' ' * 28
            f.write(('Rank     Team{0}W-L-T    Rating\n').format(spacer))
            count = 1
            lyst = []
            for team in sorted(dict.keys(),key=lambda team: array[dict[team]].head.getRating(),reverse=True):
                thisTeam = dict[team]
                rating = array[thisTeam].head.getRating()
                W = array[thisTeam].head.getWins()
                L = array[thisTeam].head.getLosses()
                T = array[thisTeam].head.getTies()
                team = team.strip()
                spacer = ' ' * (32 - len(team))
                f.write(('{0}        {1}{2}{3}-{4}-{5}    {6}\n').format(count,team,spacer,W,L,T,round(rating,4)))
                count += 1
        newfilename = 'output/SOS/strofsch_' + self._outputFilename
        with open(newfilename, 'w') as f:
            spacer = ' ' * 28
            f.write(('Rank     Team{0}W-L-T    Schedule Factor\n').format(spacer))
            count = 1
            lyst = []
            for team in sorted(dict.keys(),key=lambda team: array[dict[team]].head.getScheduleFactor(),reverse=True):
                thisTeam = dict[team]
                schedule_factor = array[thisTeam].head.getScheduleFactor()
                W = array[thisTeam].head.getWins()
                L = array[thisTeam].head.getLosses()
                T = array[thisTeam].head.getTies()
                team = team.strip()
                spacer = ' ' * (32 - len(team))
                f.write(('{0}        {1}{2}{3}-{4}-{5}    {6}\n').format(count,team,spacer,W,L,T,round(schedule_factor,4)))
                count += 1
        print("Done")