# leet087

from typing import List


class Solution1:
    def isScramble(self, s1: str, s2: str) -> bool:
        # TLE
        def f(s):
            ans = set([s])
            for i in range(1, len(s)):
                lft = f(s[:i])
                rht = f(s[i:])
                ans |= set(r+l for l in lft for r in rht)
                ans |= set(l+r for l in lft for r in rht)
            return ans 
        return s2 in f(s1)

from collections import Counter
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2): return False
        if s1 == s2: return True
        if Counter(s1) != Counter(s2): return False 
        for i in range(1, len(s1)):
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
                return True
            if self.isScramble(s1[:i], s2[-i:]) and self.isScramble(s1[i:], s2[:len(s2)-i]):
                return True
        return False

print(Solution().isScramble(s1 = "great", s2 = "rgeat"))
print(Solution().isScramble(s1 = "abcde", s2 = "caebd"))
print(Solution().isScramble(s1 = "a", s2 = "a"))
print(Solution().isScramble("abcdefghijklmn", "efghijklmncadb"))


