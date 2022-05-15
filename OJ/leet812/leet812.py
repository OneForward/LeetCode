# leet812
# %%
from itertools import combinations
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        def S(points): 
            (x1, y1), (x2, y2), (x3, y3) = points
            return abs( x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2 ) / 2
        return max( S( points3 ) for points3 in combinations(points, 3)  )


pprint(Solution().largestTriangleArea(points = [[0,0],[0,1],[1,0],[0,2],[2,0]]))


