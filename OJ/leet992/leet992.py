# leet992

from typing import List


class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
        M1, M2 = [0] * 20005, [0] * 20005
        r1, r2 = 0, 0
        c1, c2, n = 0, 0, len(A)
        ans = 0
        for x in A:
            while c1 < K and r1 < n:
                if M1[A[r1]] == 0: c1 += 1
                M1[A[r1]] += 1; r1 += 1
            while c2 <= K and r2 < n:
                if M2[A[r2]] == 0: c2 += 1
                M2[A[r2]] += 1; r2 += 1
            if c1 < K: break
            ans += r2 - r1 
            if c2 == K: ans += 1
            M1[x] -= 1 
            M2[x] -= 1 
            if M1[x] == 0: c1 -= 1
            if M2[x] == 0: c2 -= 1
        return ans 

            



print(Solution().subarraysWithKDistinct(A = [1,2,1,2,3], K = 2))
print(Solution().subarraysWithKDistinct(A = [1,2,1,3,4], K = 3))
print(Solution().subarraysWithKDistinct(A = [2,1,2,1,2], K = 2))


