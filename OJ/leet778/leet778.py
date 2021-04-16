# leet778

from typing import List

import heapq
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        # 与 1631 完全一致, O(N^2 log N)
        # 此处使用 Dijkstra 算法, 寻找最短路径, 路径计算方式为  max_{i in path} (e_i)
        n = len(grid)
        dist = [[1e4] * n for _ in range(n)]
        dist[0][0] = grid[0][0]
        Q = [(0, 0, 0)]

        while Q:
            d, x, y = heapq.heappop(Q)
            if x == n-1 and y == n-1: return d 

            for nx, ny in ((x+1, y), (x-1, y), (x, y+1), (x, y-1)):
                if nx < 0 or ny < 0 or nx >= n or ny >= n: continue
                newd = max(d, max(grid[x][y], grid[nx][ny]))
                if dist[nx][ny] > newd:
                    dist[nx][ny] = newd 
                    heapq.heappush(Q, (newd, nx, ny))
            




print(Solution().swimInWater([[0,2],[1,3]]))
print(Solution().swimInWater([[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]))


