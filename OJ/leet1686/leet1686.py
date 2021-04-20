# leet1686

from typing import List

class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        N = len(aliceValues)
        index = list(range(N))
        S = [x + y for x, y in zip(aliceValues, bobValues)]
        index.sort(key=lambda i: S[i], reverse=True )
        sA = sum(aliceValues[i] for i in index[::2])
        sB = sum(bobValues[i] for i in index[1::2])
        delta = sA - sB
        if delta == 0: return 0 
        if delta >  0: return 1
        return -1


print(Solution().stoneGameVI(aliceValues = [1,3], bobValues = [2,1]))
print(Solution().stoneGameVI(aliceValues = [1,2], bobValues = [3,1]))
print(Solution().stoneGameVI(aliceValues = [2,4,3], bobValues = [1,6,7]))


