# leet657

from typing import List

from collections import Counter
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        C = Counter(moves) 
        return C["U"] == C["D"] and C["L"] == C["R"]


print(Solution().judgeCircle("UD"))
print(Solution().judgeCircle("LL"))


