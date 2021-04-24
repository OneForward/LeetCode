# leet494

from collections import defaultdict
from typing import List


def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:]) for _ in range(dims[0])]


class Solution:
    def findTargetSumWays(self, A: List[int], target: int) -> int:
        f = {0: 1}
        for x in A:
            f, g = defaultdict(int), f
            for t, cnt in g.items():
                f[t - x] += cnt
                f[t + x] += cnt
        return f[target]


print(Solution().findTargetSumWays([1,1,1,1,1], 3))


