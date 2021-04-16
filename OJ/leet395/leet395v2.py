# leet395

from typing import List

from collections import Counter

class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        # 32ms, 递归
        for si in set(s):
            if s.count(si) < k:
                return max(self.longestSubstring(sub, k) for sub in s.split(si))
        return len(s)


print(Solution().longestSubstring(s = "weitong", k = 2))
print(Solution().longestSubstring(s = "aaabb", k = 3))
print(Solution().longestSubstring(s = "ababbc", k = 2))
print(Solution().longestSubstring("aaabbb", 3))


