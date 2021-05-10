# lcci04.01
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def findWhetherExistsPath(self, n: int, graph: List[List[int]], start: int, target: int) -> bool:
        visited = [False] * n 
        G = [[] for _ in range(n)]
        for u, v in graph:
            G[u].append(v)
        
        def dfs(u):
            if u == target: return True
            for v in G[u]:
                if not visited[v] and dfs(v): return True
            return False
        
        visited[start] = True
        return dfs(start)


print(Solution().findWhetherExistsPath(n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2))
print(Solution().findWhetherExistsPath(n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4))


