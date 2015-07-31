import unittest
import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..')))
from includes.adj_list import AdjList
from includes.team import Team
from includes.game import Game

class TestAdjList(unittest.TestCase):

    def setUp(self):
        self.test_list = AdjList()

    def tearDown(self):
        self.test_list = None

    def test_instatiation(self):
        self.assertIsNone(self.test_list.head)
        self.assertIsNone(self.test_list.tail)
        self.assertEqual(self.test_list._size, 0)

    def test_insertHead(self):
        self.test_list.insertHead("Example Team")

        self.assertEqual(self.test_list.head.getTeam(), "Example Team")
        self.assertEqual(self.test_list.tail.getTeam(), "Example Team")
        self.assertEqual(self.test_list._size, 1)

        self.test_list.insertHead("Other Team")

        self.assertEqual(self.test_list.head.getTeam(), "Other Team")
        self.assertEqual(self.test_list.tail.getTeam(), "Example Team")
        self.assertEqual(self.test_list._size, 2)

    def test_insert(self):
        self.test_list.insertHead("Example Team")
        self.test_list.insert("Other Team", 42)

        self.assertEqual(self.test_list.head.getTeam(), "Example Team")
        self.assertEqual(self.test_list.tail.getTeam2(), "Other Team")
        self.assertEqual(self.test_list._size, 2)

    def test_getSize(self):
        self.test_list.insertHead("Example Team")
        self.assertEqual(self.test_list.getSize(), 1)
        self.test_list.insertHead("Other Team")
        self.assertEqual(self.test_list.getSize(), 2)
        self.test_list.insert("Third Team", 42)
        self.assertEqual(self.test_list.getSize(), 3)

class TestTeam(unittest.TestCase):

    def setUp(self):
        self.test_team = Team("Example Team")

    def tearDown(self):
        self.test_team = None

    def test_instatiation(self):
        self.assertEqual(self.test_team._name, "Example Team")
        self.assertEqual(self.test_team._rating, 0.0)
        self.assertEqual(self.test_team._performance, 0.0)
        self.assertEqual(self.test_team._scheduleFactor, 0.0)
        self.assertEqual(self.test_team._wins, 0)
        self.assertEqual(self.test_team._losses, 0)
        self.assertEqual(self.test_team._ties, 0)
        self.assertIsNone(self.test_team.next)

    def test_getTeam(self):
        self.assertEqual(self.test_team.getTeam(), "Example Team")

    def test_get_and_set_Rating(self):
        self.assertEqual(self.test_team.getRating(), 0.0)
        self.test_team.setRating(4.2)
        self.assertEqual(self.test_team.getRating(),4.2)

    def test_get_and_set_Performance(self):
        self.assertEqual(self.test_team.getPerformance(), 0.0)
        self.test_team.setPerformance(4.2)
        self.assertEqual(self.test_team.getPerformance(),4.2)

    def test_get_and_set_ScheduleFactor(self):
        self.assertEqual(self.test_team.getScheduleFactor(), 0.0)
        self.test_team.setScheduleFactor(4.2)
        self.assertEqual(self.test_team.getScheduleFactor(),4.2)

    def test_get_and_set_Wins(self):
        self.assertEqual(self.test_team.getWins(), 0)
        self.test_team.setWins(4)
        self.assertEqual(self.test_team.getWins(),4)

    def test_get_and_set_Losses(self):
        self.assertEqual(self.test_team.getLosses(), 0)
        self.test_team.setLosses(4)
        self.assertEqual(self.test_team.getLosses(),4)

    def test_get_and_set_Ties(self):
        self.assertEqual(self.test_team.getTies(), 0)
        self.test_team.setTies(4)
        self.assertEqual(self.test_team.getTies(),4)

class TestGame(unittest.TestCase):

    def setUp(self):
        self.test_game = Game("Other Team", 42)

    def tearDown(self):
        self.test_game = None

    def test_getTeam2(self):
        self.assertEqual(self.test_game.getTeam2(), "Other Team")

    def test_getScoreDiff(self):
        self.assertEqual(self.test_game.getScoreDiff(), 42)

if __name__ == '__main__':
    unittest.main()