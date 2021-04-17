# leet886

from typing import List


class Solution:
    def possibleBipartition(self, N: int, dislikes: List[List[int]]) -> bool: 
        # 二分图检验
        color = [0] * (N+1)
        edges = [[] for _ in range(N+1)]
        for u, v in dislikes:
            edges[u].append(v)
            edges[v].append(u)
        
        def f(u, c):
            color[u] = c 
            for v in edges[u]:
                if color[v] == color[u]:  return False
                if color[v] == 0 and not f(v, 3-c): return False 
            return True
        
        for u in range(1, N+1):
            if color[u] == 0 and not f(u, 1):  return False
        return True


print(Solution().possibleBipartition(N = 4, dislikes = [[1,2],[1,3],[2,4]]))
print(Solution().possibleBipartition(N = 3, dislikes = [[1,2],[1,3],[2,3]]))
print(Solution().possibleBipartition(N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]))


