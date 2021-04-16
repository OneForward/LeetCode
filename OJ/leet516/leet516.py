# leet516

from typing import List


class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        f = [0] * (n+1) 
        prev = 0
        for i in range(n):
            for j in range(n):
                if s[i] == s[n-j-1]:
                    fj = f[j+1]
                    f[j+1] = prev + 1
                    prev = fj
                else:
                    prev = f[j+1]
                    f[j+1] = max(f[j+1], f[j])
        return f[-1]
    def longestPalindromeSubseq1(self, s: str) -> int:
        n = len(s)
        f = [[0] * (n+1) for _ in range(n+1)] 
        for i in range(n):
            for j in range(n):
                if s[i] == s[n-j-1]:
                    f[i+1][j+1] = f[i][j] + 1
                else:
                    f[i+1][j+1] = max(f[i][j+1], f[i+1][j])
        return f[-1][-1]
            
print(Solution().longestPalindromeSubseq("bbbab"))
print(Solution().longestPalindromeSubseq("cbbd"))
print(Solution().longestPalindromeSubseq("aabaa"))


