# leet149

from typing import List

from collections import defaultdict
from fractions import Fraction
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        ans = 1
        for i in range(n-1):
            x1, y1 = points[i]
            C = defaultdict(int)
            Vertical = 1
            for j in range(i+1, n):
                x2, y2 = points[j]
                if x1 == x2: Vertical += 1
                else:
                    k = Fraction(y1-y2, x1-x2)
                    C[k] += 1
            ans = max(ans, Vertical)
            if C: ans = max(ans, max(C.values()) + 1)
        return ans 


print(Solution().maxPoints([[1,1]]))
print(Solution().maxPoints([[1,1],[2,2],[3,3]]))
print(Solution().maxPoints([[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]))


