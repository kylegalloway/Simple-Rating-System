import unittest
import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..')))
from includes.adj_list import AdjList

class TestAdjList(unittest.TestCase):

    def setUp(self):
        self.test_list = AdjList()

    def tearDown(self):
        self.test_list = None

    def test_instatiation(self):
        self.assertEqual( self.test_list.head, None)
        self.assertEqual( self.test_list.tail, None)
        self.assertEqual( self.test_list._size, 0)

    def test_insertHead(self):
        self.test_list.insertHead("Example Team")

        self.assertEqual( self.test_list.head.getTeam(), "Example Team")
        self.assertEqual( self.test_list.tail.getTeam(), "Example Team")
        self.assertEqual( self.test_list._size, 1)

        self.test_list.insertHead("Other Team")

        self.assertEqual( self.test_list.head.getTeam(), "Other Team")
        self.assertEqual( self.test_list.tail.getTeam(), "Example Team")
        self.assertEqual( self.test_list._size, 2)

    def test_insert(self):
        self.test_list.insertHead("Example Team")
        self.test_list.insert("Other Team", 42)

        self.assertEqual( self.test_list.head.getTeam(), "Example Team")
        self.assertEqual( self.test_list.tail.getTeam2(), "Other Team")
        self.assertEqual( self.test_list._size, 2)

    def test_getSize(self):
        self.test_list.insertHead("Example Team")

        self.assertEqual(self.test_list.getSize(), 1)

        self.test_list.insertHead("Other Team")

        self.assertEqual(self.test_list.getSize(), 2)

        self.test_list.insert("Third Team", 42)

        self.assertEqual(self.test_list.getSize(), 3)


if __name__ == '__main__':
    unittest.main()