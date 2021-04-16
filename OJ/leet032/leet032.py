# leet032

from typing import List


class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if len(s) <= 1: return 0
        L = [0] * len(s)
        if s[0:2] == '()': L[1] = 2
        for i in range(2, len(s)):
            if s[i] == '(':
                L[i] = 0
            else:
                if s[i - 1] == '(':
                    L[i] = L[i - 2] + 2
                elif i - L[i - 1] - 1 >= 0 and s[i - L[i - 1] - 1] == '(':
                    L[i] = L[i - L[i - 1] - 2] + L[i-1] + 2
                else:
                    L[i] = 0
        return max(L)


print(Solution().longestValidParentheses("())"))


