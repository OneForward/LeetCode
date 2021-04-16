# leet357

from typing import List


class Solution1:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0: return 1
        if n == 1: return 10

        f20, f2 = 0, 9
        f1 = 1
        ans = 10
        for i in range(2, n+1):
            f1 = (11 - i) * (f1 + f20)
            f20, f2 = f2, (10 - i) * f2
            ans += f1 + f2 
        return ans

class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0: return 1

        f = 0
        cnt = 0
        ten = 1
        for i in range(2, n+1):
            f = 10 * f + (i-1) * (9 * ten - f)
            ten *= 10 
            cnt += f 
        return 10 * ten - cnt


print(Solution().countNumbersWithUniqueDigits(0))
print(Solution().countNumbersWithUniqueDigits(1))
print(Solution().countNumbersWithUniqueDigits(2))
print(Solution().countNumbersWithUniqueDigits(3))


