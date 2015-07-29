'''
	Simple Rating System
    by: Kyle Galloway

	# A rudimentary college football rating system.
'''
import sys
import time
from includes.graph import Graph

def main(filename):
	G = Graph(filename)
	G.buildGraph()
	print()
	G.rateTeams()
	print()
	G.printRatings()
	print()

main(sys.argv[1])
