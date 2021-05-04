# leet1473

from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], M: int, C: int, T: int) -> int:
        MAX = int(1e10)
        f = init([M+1, T+1, C], MAX)
        f[0][0] = [0] * C
        for m in range(1, M+1):
            if houses[m-1]:
                c=  houses[m-1] - 1
                for t in range(1, T+1):
                    v = f[m-1][t][c]
                    for x in range(C):
                        if c == x: continue
                        v = min(v, f[m-1][t-1][x])
                    f[m][t][c] = v 
                continue
            for t in range(1, T+1):
                for c in range(C):
                    v = f[m-1][t][c]
                    for x in range(C):
                        if c == x: continue
                        v = min(v, f[m-1][t-1][x])
                    f[m][t][c] = v + cost[m-1][c]
        # pprint(f)
        ans =  min(f[M][T])
        if ans >= MAX: return -1
        return ans


print(Solution().minCost(houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], M = 5, C = 2, T = 3 ))
print(Solution().minCost(houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], M = 5, C = 2, T = 3 ))
print(Solution().minCost(houses = [0,0,0,0,0], cost = [[1,10],[10,1],[1,10],[10,1],[1,10]], M = 5, C = 2, T = 5 ))
print(Solution().minCost(houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], M = 4, C = 3, T = 3 ))


