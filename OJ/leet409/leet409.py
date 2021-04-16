# leet409

from typing import List

from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        C = Counter(s)
        Nodd = 0
        for cnt in C.values(): 
            if cnt % 2: Nodd += 1
        return len(s) - max(Nodd-1, 0)

print(Solution().longestPalindrome('abccccdd'))


