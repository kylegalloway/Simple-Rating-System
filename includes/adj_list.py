class Adjlist():

    def __init__(self):
        self.head = None
        self.tail = None
        self._size = 0

    def insertHead(self, name):
        self.head = Team(name)
        self.tail = self.head
        self._size += 1

    def insert(self, team2, scoreDiff):
        curr = self.tail
        curr.next = Game(team2, scoreDiff)
        self.tail = curr.next
        self._size += 1

    def getSize(self):
        return self._size