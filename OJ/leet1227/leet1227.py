# leet1227

from typing import List


class Solution:
    def nthPersonGetsNthSeat(self, n: int) -> float:
        if n == 1: return 1
        return 0.5

for n in range(1, 10):
    print(Solution().nthPersonGetsNthSeat(n))


