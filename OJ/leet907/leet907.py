# leet907

from typing import List


class Solution:
    def sumSubarrayMins(self, A: List[int]) -> int:
        L, ans = [], []
        for i, x in enumerate(A):
            while L and A[L[-1]] >= x: L.pop()
            curr = x * (i + 1)
            if L: curr = curr - x * (L[-1] + 1)  + ans[L[-1]]
            L.append(i)
            ans.append( curr  )
        return sum(ans)


print(Solution().sumSubarrayMins(A = [3,1,2,4]))
print(Solution().sumSubarrayMins(A = [11,81,94,43,3]))


