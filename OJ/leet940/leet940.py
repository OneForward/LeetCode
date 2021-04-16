# leet940

from typing import List

class Solution1:
    def distinctSubseqII(self, s: str) -> int:
        n = len(s)
        f = [1] * (n+1)
        for i in range(1, n+1):
            f[i] = 2 * f[i-1]
            for j in range(i-1, 0, -1):
                if s[j-1] == s[i-1]:
                    f[i] -= f[j-1]
                    break
        return (f[n] - 1) % (1000000007)

class Solution:
    def distinctSubseqII(self, s: str) -> int:
        n = len(s)
        f = [1] * (n+1)
        g = [-1] * (n)
        D = {}
        for i, si in enumerate(s):
            if si in D: g[i] = D[si]
            D[si] = i 
        
        for i in range(1, n+1):
            f[i] = 2 * f[i-1]
            if g[i-1] != -1:
                f[i] -= f[g[i-1]]
        return (f[n] - 1) % (1000000007)


print(Solution().distinctSubseqII("abc"))
print(Solution().distinctSubseqII("aba"))
print(Solution().distinctSubseqII("aaa"))


