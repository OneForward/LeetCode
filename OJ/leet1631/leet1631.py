# leet1631

from typing import List

class UnionFind:
    def __init__(self, n) -> None:
        self.P = [-1] * n

    def find(self, i):
        P = self.P 
        if P[i] < 0: return i 
        P[i] = self.find(P[i])
        return P[i]
    
    def merge(self, i, j):
        P = self.P 
        ri, rj = self.find(i), self.find(j)
        if ri == rj: return 
        if P[ri] < P[rj]: P[ri] += P[rj]; P[rj] = ri 
        else: P[rj] += P[ri]; P[ri] = rj 

class Solution:
    def minimumEffortPath1(self, heights: List[List[int]]) -> int:
        # O(M N log MN ), 并查集
        n, m = len(heights), len(heights[0])
        nm = n * m

        def fdist(i1, j1, i2, j2):
            return abs(heights[i1][j1] - heights[i2][j2])

        E = list( (i*m+j, i*m+j+1,   fdist(i, j, i, j+1)) for i in range(n) for j in range(m-1)) + \
            list( (i*m+j, (i+1)*m+j, fdist(i, j, i+1, j)) for i in range(n-1) for j in range(m)) 
        E = sorted(E, key=lambda e: e[-1]) # 此处排序是灵魂，提供了贪心的策略

        UF = UnionFind(nm)
        for (pos1, pos2, d) in E:
            UF.merge(pos1, pos2)
            if UF.find(0) == UF.find(nm-1): return d 
        return 0 

    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        # O(M N log MN ), Dijkstra
        n, m = len(heights), len(heights[0])
        import heapq 

        dist = [[float("inf") for _ in range(m)] for _ in range(n)]
        dist[0][0] = 0

        Q = [(0, 0, 0)]
        while Q:
            d, x, y = heapq.heappop(Q) # 默认排序元组，根据首位排序
            if (x, y) == (n-1, m-1): return d 

            for nx, ny in ((x, y+1), (x, y-1), (x+1, y), (x-1, y)):
                if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
                newdist = max(abs(heights[nx][ny] - heights[x][y]), d)
                if newdist < dist[nx][ny]: # 松弛操作
                    dist[nx][ny] = newdist
                    heapq.heappush(Q, (newdist, nx, ny))      
                    print(Q)
        return 0 
            
        

# print(Solution().minimumEffortPath(heights = [[3]]))
print(Solution().minimumEffortPath(heights = [[1,2,2],[3,8,2],[5,3,5]]))
# print(Solution().minimumEffortPath(heights = [[1,2,3],[3,8,4],[5,3,5]]))
# print(Solution().minimumEffortPath(heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]))


