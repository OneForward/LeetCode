# leet1406

from typing import List


class Solution:
    def stoneGameIII(self, values : List[int]) -> str:
        N = len(values)
        f = [0 for _ in range(N+1)]
        g = [0 for _ in range(N+1)]
        for i in range(N-1, -1, -1):
            ans1, ans2 = -1e9, -1e9 
            fi = 0
            for j in range(i, min(i+3, N)):
                fi += values[j]
                if ans1 < fi + g[j+1]: ans1, ans2 = fi + g[j+1],  f[j+1]
            f[i] , g[i] = ans1, ans2

        ans1, ans2 =  f[0], g[0]
        if ans1 == ans2: return "Tie"
        if ans1 > ans2: return "Alice"
        return "Bob"



print(Solution().stoneGameIII(values = [1,2,3,7]))
print(Solution().stoneGameIII(values = [1,2,3,-9]))
print(Solution().stoneGameIII(values = [1,2,3,6]))
print(Solution().stoneGameIII(values = [1,2,3,-1,-2,-3,7]))
print(Solution().stoneGameIII(values = [-1,-2,-3]))


