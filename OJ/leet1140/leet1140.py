# leet1140

from typing import List


class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        memo = {}
        N = len(piles)
        def f(start, M):
            if (start, M) in memo: return memo[(start, M)]
            if start + 2* M >= N: return sum(piles[start:]), 0
            L = [ f(x + start, max(M, x))  for x in range(1, 2 * M + 1)  ]
            A = [ piles[start] ]
            for x in range(1, 2 * M): A.append(A[-1] + piles[start + x])
            ans1, ans2 = 0, 0
            for f1, (g, f2) in zip(A, L):
                if ans1 < f1 + f2: ans1, ans2 = f1 + f2, g 
            memo[(start, M)] = (ans1, ans2)
            return ans1, ans2
        
        return f(0, 1)[0]


print(Solution().stoneGameII(piles = [1,2,3,4,5,100]))
print(Solution().stoneGameII(piles = [2,7,9,4,4]))


