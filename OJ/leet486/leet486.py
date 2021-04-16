# leet486

from typing import List

from copy import deepcopy 
from pprint import pprint
class Solution:
    def PredictTheWinner1(self, A: List[int]) -> bool:
        n = len(A)
        f = [[0]*n for _ in range(n)]
        for i in range(n):
            f[i][i] = A[i]
        for i in range(n-2,-1,-1):
            for j in range(i+1,n):
                f[i][j] = max(A[j]-f[i][j-1],A[i]-f[i+1][j])
        pprint(f)
        return f[0][-1] >= 0
    

    def PredictTheWinner(self, A: List[int]) -> bool:
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



print(Solution().PredictTheWinner([0]))
print(Solution().PredictTheWinner([1, 5, 2]))
print(Solution().PredictTheWinner([1, 5, 233, 7]))
print(Solution().PredictTheWinner([0,0,7,6,5,6,1]))


