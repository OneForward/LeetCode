# leet1155

from typing import List


class Solution:
    def numRollsToTarget(self, dices: int, facets: int, target: int) -> int:
        D = {}
        MOD = 1000000007
        def f(target, dices):
            key = (target, dices)
            if key in D: return D[key]
            if dices == 1:
                if 1 <= target <= facets: return 1
                else: return 0
            D[key] = sum( f(target-i, dices-1) for i in range(1, facets+1) ) % MOD
            return D[key]
        return f(target, dices)




print(Solution().solver())


