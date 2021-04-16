# leet343

from typing import List


class Solution:
    def integerBreak(self, n: int) -> int:
        if n <= 3: return n - 1

        if n % 3 == 0: return 3 ** (n // 3)
        elif n % 3 == 1: return 3 ** ((n-4) // 3) * 4
        else: return 3 ** ((n-2) // 3) * 2


print(Solution().integerBreak(2))
print(Solution().integerBreak(3))
print(Solution().integerBreak(10))
print(Solution().integerBreak(40))


