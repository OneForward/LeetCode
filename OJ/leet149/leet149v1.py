# leet149

from typing import List

from collections import defaultdict
from fractions import Fraction
from math import sqrt
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        C = defaultdict(int)
        for i in range(1, n):
            x1, y1 = points[i]
            for j in range(i):
                x2, y2 = points[j]
                if x1 == x2: C[(None, x1)] += 1
                else:
                    k = Fraction(y1-y2, x1-x2)
                    b = y1 - k * x1 
                    C[(k, b)] += 1
        # for k, v in C.items():
        #     print(k, ": ", v)
        return int(sqrt( 2 * max(C.values()))) + 1


print(Solution().maxPoints([[1,1],[2,2],[3,3]]))
print(Solution().maxPoints([[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]))


