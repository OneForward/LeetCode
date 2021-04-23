# leet491

from typing import List


def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:]) for _ in range(dims[0])]


class Solution:
    def findSubsequences(self, A: List[int]) -> List[List[int]]:
        S = set()
        for i in range(1, len(A)):
            x = A[i]
            for v in S.copy():
                if v[-1] <= x:
                    S.add( tuple(list(v) + [x]) )
            for j in range(i):
                if A[j] <= x: S.add(tuple((A[j], x)))
        return [list(v) for v in S]


print(Solution().findSubsequences([4, 6, 7, 7]))


