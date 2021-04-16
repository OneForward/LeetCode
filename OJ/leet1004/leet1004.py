# leet1004

from typing import List


class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        # f(l, r) = # number of 0s in A[l, r]
        lft, rht = 0, 0
        f = 0
        ans = 0
        while rht < len(A):
            if A[rht] == 0:
                f += 1
                while f > K:
                    if A[lft] == 0: f -= 1
                    lft += 1
            rht += 1
            ans = max(ans, rht-lft)
        return ans




print(Solution().longestOnes(A = [1,1,1,0,0,0,1,1,1,1,0], K = 2))
print(Solution().longestOnes(A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3))


