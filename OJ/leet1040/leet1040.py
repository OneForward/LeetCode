# leet1040

from typing import List


class Solution:
    def numMovesStonesII(self, A: List[int]) -> List[int]:
        # 最小值，使用长度为 N 的滑窗(长度指数据范围)，考察滑窗内的数的最多个数
        # 最大值，第一次一定会失去最左端或最右端的间隙，但其余全部间隙都可以占用
        A.sort()
        N = len(A)
        gap = min(A[1] - A[0], A[-1] - A[-2])
        maxCnt = A[-1] - A[0] - N - gap + 2


        minCnt, rht = maxCnt, 0 
        for lft in range(N):
            while rht < N and A[rht] - A[lft] < N: rht += 1
            cnt = rht - lft
            cost = N - cnt 
            if cnt == N - 1 and A[rht - 1] - A[lft] + 1 == N - 1:
                cost = 2
            minCnt = min(minCnt, cost)
        return [minCnt, maxCnt]


print(Solution().numMovesStonesII([7,4,9]))
print(Solution().numMovesStonesII([3,4,5,6,10]))
print(Solution().numMovesStonesII([100,101,104,102,103]))
print(Solution().numMovesStonesII([1,2,3,4,7]))
print(Solution().numMovesStonesII([1,2,3,4,6]))


