from includes.team import Team
from includes.game import Game

class AdjList():

    def __init__(self):
        self.head, self.tail = None, None
        self._size = 0

    def getSize(self): return self._size

    def insertHead(self, name):
        self.tail = self.head
        self.head = Team(name)
        if self.tail == None:
            self.tail = self.head
        self._size += 1

    def insert(self, team2, scoreDiff):
        curr = self.tail
        curr.next = Game(team2, scoreDiff)
        self.tail = curr.next
        self._size += 1