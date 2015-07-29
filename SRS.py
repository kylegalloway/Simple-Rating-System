'''
	File: Program4.py
	by: Kyle Galloway

	# A rudimentary college football ranking system.
	# Updated to cap victory margins to be between 7 and 21
	# Updated to give winning team 7 extra points
'''
import sys
import time
from includes.team import Team
from includes.game import Game
from includes.adj_list import Adjlist
from includes.graph import Graph

def main(filename):
	# startTime = time.time()
	G = Graph(filename)
	G.buildGraph()
	print()
	G.rateTeams()
	print()
	G.printRatings()
	print()
	# print(round(time.time() - startTime,4))

main(sys.argv[1])