# leet342

from typing import List


class Solution:
    # 要点 x & (x - 1) 判断是否是 2 的幂次, 4^k % 3 == 1, 4^k * 2 % 3 == 2
    def isPowerOfFour1(self, x: int) -> bool:
        return  any((x == (1<<i) for i in range(0, 32, 2)) )
    def isPowerOfFour(self, x: int) -> bool:
        return  (x & (x-1)) == 0 and (x % 3 == 1)


print(Solution().isPowerOfFour(1))
print(Solution().isPowerOfFour(1<<2))
print(Solution().isPowerOfFour(1<<16))
print(Solution().isPowerOfFour(1<<30))
print(Solution().isPowerOfFour(1<<32))


