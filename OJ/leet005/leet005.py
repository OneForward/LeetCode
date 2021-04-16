class Solution:
    def longestPalindrome(self, s: str) -> str:
        # O(N), manach
        # C 表示回文串的中心，用 R 表示回文串的右边半径坐标，
        # 所以 R = C + P[ C ] 。
        # C 和 R 所对应的回文串是当前循环中 R 最靠右的回文串
        snew = '.'.join('$' + s + '%')
        p = [0] * len(snew)
        C, R = 0, 0
        for i in range(1, len(p)-1):
            if i < R:
                p[i] = min(R-i, p[2*C-i])
            while snew[i-p[i]-1] == snew[i+p[i]+1]:
                p[i] += 1
            if i + p[i] > R:
                R = i+p[i]
                C = i
        print(p)
        max_i, max_v = 0, 0
        for i, pi in enumerate(p):
            if max_v < pi:
                max_i, max_v = i, pi
        max_v -= 1
        return s[(max_i-max_v)//2:(max_i+max_v)//2-1]

class Solution1:
    def longestPalindrome(self, s: str) -> str:
        snew = '.'.join('$' + s + '%')
        p = [1] * len(snew)
        i0, ir = 0, 0
        for i in range(2, len(p)-1):
            if i < ir:
                p[i] = min(ir-i, p[2*i0-i])
            while snew[i-p[i]] == snew[i+p[i]]:
                p[i] += 1
            if ir < i+p[i]-1:
                ir = i+p[i]-1
                i0 = i
        max_i, max_v = 0, 0
        for i, pi in enumerate(p):
            if max_v < pi:
                max_i, max_v = i, pi
        return s[(max_i-max_v)//2:(max_i+max_v)//2-1]

sol = Solution()

s = 'abcba'
print(sol.longestPalindrome(s))