# leet421

from typing import List


class Solution:
    def findMaximumXOR1(self, nums: List[int]) -> int:
        # 哈希法，
        # 要点 x ^ a = b  =>  x ^ b = a,  a ^ b = x;
        L = max(len(bin(x)) for x in nums)
        ans = 0
        for i in range(L)[::-1]:
            ans <<= 1
            curXor = ans | 1;
            test = set(x >> i for x in nums)
            ans = ans | any(curXor ^ x in test for x in test)
        return ans

    def findMaximumXOR(self, nums: List[int]) -> int:
        # 字典树法
        # 对每个数在 Trie 中寻找最大的互补对
        L = max(len(bin(x)) for x in nums)
        ans = 0
        for i in range(L)[::-1]:
            ans <<= 1
            curXor = ans | 1;
            test = set(x >> i for x in nums)
            ans = ans | any(curXor ^ x in test for x in test)
        return ans







print(Solution().findMaximumXOR([3, 10, 5, 25, 2, 8]))
print(Solution().findMaximumXOR([8, 10, 2]))


