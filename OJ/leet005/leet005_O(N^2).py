class Solution:
    def longestPalindrome(self, s0: str) -> str:
        # O(N^2)
        s = '.'.join(s0)
        s = f'.{s}.'
        N = len(s)
        maxc, maxn = 0, -1
        for c in range(1, N-1):
            for n in range(min(c+1, N-c)):
                if s[c-n] != s[c+n]: break 
                if n > maxn: maxn = n; maxc = c 
        lft, rht = (maxc - maxn) // 2, (maxc + maxn + 1) // 2 
        return s0[lft:rht]


print(Solution().longestPalindrome('abcba'))
print(Solution().longestPalindrome('babad'))
print(Solution().longestPalindrome('cbbd'))
print(Solution().longestPalindrome('a'))
print(Solution().longestPalindrome('ac'))
print(Solution().longestPalindrome('acc'))