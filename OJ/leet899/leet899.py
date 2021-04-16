# leet899

from typing import List


class Solution:
    def orderlyQueue(self, s: str, K: int) -> str:
        if K > 1: return ''.join(sorted(s))
        # K=1
        return sorted(s[i:] + s[:i] for i in range(len(s)))[0]


print(Solution().orderlyQueue(s = "cba", K = 1))
print(Solution().orderlyQueue(s = "baaca", K = 3))


