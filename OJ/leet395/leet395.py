# leet395

from typing import List

from collections import Counter

class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        # 32ms, 递归
        C, n = Counter(s), len(s)
        if min(C.values()) >= k: return n
        if max(C.values()) < k: return 0

        lft, rht, ans = -1, 0, 0
        for rht, si in enumerate(s):
            if C[si] >= k: continue
            if ans < rht - lft - 1:
                ans = max(ans, self.longestSubstring(s[lft+1:rht], k))
            lft = rht
        
        if ans < n - lft - 1:
            ans = max(ans, self.longestSubstring(s[lft+1:n], k))
        return ans


print(Solution().longestSubstring(s = "weitong", k = 2))
print(Solution().longestSubstring(s = "aaabb", k = 3))
print(Solution().longestSubstring(s = "ababbc", k = 2))
print(Solution().longestSubstring("aaabbb", 3))


