# leet456

from typing import List


class Solution:
        
    def find132pattern1(self, A: List[int]) -> bool:
        # TLE, O(N^2), 
        for i in range(len(A)):
            curMax = A[i]
            for j in range(i+1, len(A)):
                if A[i] < A[j]:
                    if A[j] < curMax: return True 
                    curMax = A[j] 
        return False

    def find132pattern(self, A: List[int]) -> bool:
        # O(N) 栈
        if len(A) < 3: return False

        minA = [A[0]]
        for i in range(1, len(A)):
            minA.append(min(minA[-1], A[i]))

        # 维护一个递减栈
        # [0..j) aj [j+1,..n)
        # M1         M2
        # 要求 M1 < M2 < aj 
        # 要点：
        # 到第 j 个数时，栈中小于 min(A[0..j]) 的数都是无用的
        S = []
        for j in range(len(A)-1, -1, -1):
            if A[j] > minA[j]:
                while S and S[-1] <= minA[j]: S.pop()
                if S and S[-1] < A[j]: return True
                S.append(A[j])
        return False


print(Solution().find132pattern([1, 2, 3, 4]))
print(Solution().find132pattern([3, 1, 4, 2]))
print(Solution().find132pattern([-1, 3, 2, 0]))
print(Solution().find132pattern([1,0,1,-4,-3]))
print(Solution().find132pattern([3,5,0,3,4]))


