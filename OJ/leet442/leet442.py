# leet442

from typing import List


class Solution:
    def findDuplicates1(self, A: List[int]) -> List[int]:
        for i in range(len(A)):
            while A[A[i]-1] != A[i]:
                A[A[i]-1], A[i] = A[i], A[A[i]-1] 
        return [ x for i, x in enumerate(A) if x != i+1 ] 
    
    def findDuplicates(self, A: List[int]) -> List[int]:
        ans = []
        for x in A:
            i = abs(x) - 1
            if A[i] > 0:
                A[i] *= -1
            else:
                ans.append(abs(x))
        return ans


print(Solution().findDuplicates([4,3,2,7,8,2,3,1]))


