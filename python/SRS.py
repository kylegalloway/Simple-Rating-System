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

if (len(sys.argv) == 2):
    main(sys.argv[1])
elif(len(sys.argv) == 1):
    import os
    for f in os.listdir("csv"):
        main("csv/"+f)
else:
    print("Run with "+sys.argv[0]+" to produce all possible rankings.\n")
    print("Run with "+sys.argv[0]+" <csv/filename> to produce rankings for <filename>.\n")
