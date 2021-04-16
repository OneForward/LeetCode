# leet740

from typing import List


from collections import Counter
class Solution1:
    def deleteAndEarn(self, A: List[int]) -> int:
        C = Counter(A)
        A = sorted(C.keys())
        f = [0] * len(A)
        g = [0] * len(A)
        for i, x in enumerate(A):
            f[i] = C[x] * x
            if i >= 1:
                if x - A[i-1] == 1:
                    if i >= 2: f[i] += g[i-2]
                else:
                    f[i] += g[i-1]
            g[i] = f[i]
            if i >= 1: g[i] = max(f[i], g[i-1])
        return g[-1]

from collections import Counter
class Solution:
    def deleteAndEarn(self, A: List[int]) -> int:
        C = Counter(A)
        A = sorted(C.keys())
        gi2, gi1, gi, prev = 0, 0, 0, 0
        for i, x in enumerate(A):
            fi = C[x] * x
            if x - prev == 1: fi += gi2
            else: fi += gi1
            gi = max(fi,  gi1)
            gi2, gi1, prev = gi1, gi, x
        return gi


        


print(Solution().deleteAndEarn([1,1,1,2,4,5,5,5,6]))
print(Solution().deleteAndEarn([3,4,2]))
print(Solution().deleteAndEarn([2, 2, 3, 3, 3, 4]))


