# leet793

from typing import List


class Solution:
    def preimageSizeFZF(self, K: int) -> int:
        def f(x):
            ans = 0
            while x: 
                ans += x // 5
                x //= 5
            return ans 
        lo, hi = K , 1<<32
        while lo < hi:
            mid = (lo + hi) // 2
            if f(mid) >= K: hi = mid 
            else: lo = mid + 1
        
        cnt = 0 
        for x in range(lo, lo+5):
            if f(x) == K: cnt += 1
        return cnt


print(Solution().preimageSizeFZF(25))
print(Solution().preimageSizeFZF(0))
print(Solution().preimageSizeFZF(3))
print(Solution().preimageSizeFZF(5))


