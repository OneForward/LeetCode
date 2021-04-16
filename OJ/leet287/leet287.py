# leet287

from typing import List


from collections import Counter
class Solution:
    def findDuplicate(self, A: List[int]) -> int:
        x = A[0]
        while A[x]:
            newx = A[x]
            A[x] = 0
            x = newx
        return x




print(Solution().findDuplicate([1,3,4,2,2]))


