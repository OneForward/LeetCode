# leet5724

from typing import List
from operator import *
class Solution:
    def minAbsoluteSumDiff(self, A: List[int], B: List[int]) -> int:
        n = len(B)
        iB = list(range(len(B)))
        iB.sort(key=lambda i: B[i])
        Asorted = sorted(A)
        pA, delta = 0, 0
        for i in iB:
            while pA < n and Asorted[pA] < B[i]: pA += 1
            if pA >= 1: delta = max( abs(A[i] - B[i]) - abs(Asorted[pA-1] - B[i]), delta )
            if pA < n: delta = max( abs(A[i] - B[i]) - abs(Asorted[pA] - B[i]), delta )
        return sum(abs(a - b) for a, b in zip(A, B)) - delta


print(Solution().minAbsoluteSumDiff(  [1,7,5],   [2,3,5]))
print(Solution().minAbsoluteSumDiff(    [2,4,6,8,10],   [2,4,6,8,10]))
print(Solution().minAbsoluteSumDiff(    [1,10,4,4,2,7],   [9,3,5,1,7,4]))


