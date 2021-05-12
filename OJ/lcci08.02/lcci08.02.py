# lcci08.02
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def pathWithObstacles(self, G: List[List[int]]) -> List[List[int]]:
        R, C = len(G), len(G[0])
        
        def dfs(x, y, path):
            if x < 0 or x >= R or y < 0 or y >= C or G[x][y]: return False
            path.append([x,y])
            G[x][y] = 1

            if x == R-1 and y == C-1: return True
            if dfs(x + 1, y, path): return True
            if dfs(x, y + 1, path): return True

            path.pop()
            return False
        path = []
        dfs(0, 0, path) 
        return path 


print(Solution().pathWithObstacles([
  [0,0,0],
  [0,1,0],
  [0,0,0]
]))
print(Solution().pathWithObstacles([
  [0]
]))
print(Solution().pathWithObstacles([
  [1]
]))
print(Solution().pathWithObstacles([
    [0,0,0,0,0],
    [0,0,0,0,1],
    [0,0,0,1,0],
    [0,0,0,0,0]
]))


