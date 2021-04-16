# leet389

from typing import List

from collections import Counter, defaultdict
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        S = defaultdict(int, Counter(s))
        T = Counter(t)
        for ti, cnt in T.items():
            if S[ti] != cnt:
                return ti 

print(Solution().findTheDifference(s = "abcd", t = "abcde"))
print(Solution().findTheDifference(s = "a", t = "aa"))


