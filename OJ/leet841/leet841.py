# leet841

from typing import List
import unittest

class Solution:
    def canVisitAllRooms(self, edges: List[List[int]]) -> bool:
        visited = [False] * len(edges)

        def dfs(root):
            visited[root] = True
            for x in edges[root]:
                if not visited[x]:
                    dfs(x)
        
        dfs(0)
        return all(visited)
            


class TestSolution(unittest.TestCase):
    def setUp(self) -> None:
        self.sol = Solution()

    def test_cases(self):
        self.assertEqual( self.sol.canVisitAllRooms([[1],[2],[3],[]]), True )
        self.assertEqual( self.sol.canVisitAllRooms([[1,3],[3,0,1],[2],[0]]), False )


# print(Solution().canVisitAllRooms([[1],[2],[3],[]]))
# print(Solution().canVisitAllRooms([[1,3],[3,0,1],[2],[0]]))


unittest.main()