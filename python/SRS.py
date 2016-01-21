'''
    Simple Rating System
    by: Kyle Galloway

    # A rudimentary college football rating system.
'''
import sys
import time
from includes.graph import Graph
from includes.file_io import FileIO

def main(filename):
    G = Graph()
    file = FileIO(filename)
    G.buildGraph(file)
    print()
    G.rateTeams()
    print()
    teams = G.getTeams()
    teamNames = G.getTeamNames()
    file.printRatings(teamNames,teams)
    print()

main(sys.argv[1])
