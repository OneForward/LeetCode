# leet877

from typing import List


class Solution:
    def stoneGame1(self, A: List[int]) -> bool:
        # 偶数个堆，且总和为奇数
        # 故可以将这些堆交错染色，黑白色，则必有一种颜色的堆总数大于另一堆
        # 先手总可以取下这个最优颜色堆
        return True

    def stoneGame(self, A: List[int]) -> bool:
        # f(i, j): A[i..j] 上先手比后手最多多拿的分数
        # f(i, j) = max( A[i] - f(i+1, j), A[j] - f(i, j-1) )
        n = len(A)
        memo = [[None]*n for _ in range(n)]
        for i in range(n): memo[i][i] = A[i]

        def f(i, j):
            if i > j: return 0
            if memo[i][j] is not None: return memo[i][j]

            memo[i][j] = max( A[i] - f(i+1, j), A[j] - f(i, j-1) )
            return memo[i][j]
        
        return f(0, n-1) >= 0

print(Solution().stoneGame([5,3,4,5]))
import random
for _ in range(100):
    A = random.choices(range(10), k=10)
    if sum(A) % 2 == 0: continue
    print(A)
    print(Solution().stoneGame(A))


