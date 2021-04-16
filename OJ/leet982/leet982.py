# leet982

from typing import List

class Solution:
    def countTriplets(self, A: List[int]) -> int:
        up = 1
        for x in A:
            while x >= up: up <<= 1

        M = [0] * up
        allone = up - 1 # 0b1111
        for x in A:
            mask = allone ^ x
            x = mask
            while True:
                M[x] += 1
                if x == 0: break
                x = (x-1) & mask 
                # 从 x 开始降序，依次将 出现 1 的地方变为 0, 循环发生 2 ^ #1 次, #1 为 1 bit 位的数目
                
        cnt = 0
        for x in A: 
            for y in A:
                cnt += M[x & y]
        return cnt

print(Solution().countTriplets([4,1,0]))
# print(Solution().countTriplets([2,1,3]))
# print(Solution().countTriplets([4]))

x = 0b10
allone = 0b1111
mask = allone ^ x
x = mask
while True:
    print(bin(x))
    if x == 0: break
    x = (x-1) & mask
    