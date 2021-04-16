# leet461

from typing import List


class Solution:
    def hammingDistance1(self, x: int, y: int) -> int:
        ans = 0
        z = x ^ y 
        while z:
            if z & 1: ans += 1
            z >>= 1 
        return ans 

    def hammingDistance2(self, x: int, y: int) -> int:
        return bin(x^y).count('1')

    def hammingDistance(self, x: int, y: int) -> int:
        ans = 0
        z = x ^ y
        while z:
            ans += 1
            z &= (z - 1)
        return ans


print(Solution().hammingDistance(x = 1, y = 4))


