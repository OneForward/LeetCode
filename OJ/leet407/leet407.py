# leet407

from typing import List
from pprint import pprint
from copy import deepcopy 
class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        # WA
        m, n = len(heightMap), len(heightMap[0])
        upmax, dnmax, lfmax, rhmax = [deepcopy(heightMap) for _ in range(4)] 
        for i in range(1, m):
            for j in range(n):
                upmax[i][j] = max(upmax[i-1][j], heightMap[i][j])
        for i in range(m):
            for j in range(1, n):
                lfmax[i][j] = max(lfmax[i][j-1], heightMap[i][j])
        for i in range(m):
            for j in range(n-2, -1, -1):
                rhmax[i][j] = max(rhmax[i][j+1], heightMap[i][j])
        for i in range(m-2, -1, -1):
            for j in range(n):
                dnmax[i][j] = max(dnmax[i+1][j], heightMap[i][j])
        for x in [upmax, dnmax, lfmax, rhmax]:
            pprint(x)
        S = 0
        for i in range(1, m-1):
            for j in range(1, n-1):
                minNeighbor = min(upmax[i][j], 
                                  dnmax[i][j], 
                                  lfmax[i][j], 
                                  rhmax[i][j])
                print(f'({i}, {j}): minVal => {minNeighbor}, originVal => {heightMap[i][j]}')
                S += min(upmax[i][j], dnmax[i][j], lfmax[i][j], rhmax[i][j]) - heightMap[i][j]
        return S



# print(Solution().trapRainWater([
#   [1,4,3,1,3,2],
#   [3,2,1,3,2,4],
#   [2,3,3,2,3,1]
# ]))
print(Solution().trapRainWater([
    [12,13,1,12],
    [13,4,13,12],
    [13,8,10,12],
    [12,13,12,12],
    [13,13,13,13]
]))


