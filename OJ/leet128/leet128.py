# leet128

from typing import List


class Solution1:
    def longestConsecutive(self, nums: List[int]) -> int:
        # O(N)
        S = set(nums)
        ans = 0
        for x in nums:
            if x not in S: continue
            maxn = 1
            y = x + 1
            while y in S: S.remove(y); maxn += 1; y += 1
            y = x - 1
            while y in S: S.remove(y); maxn += 1; y -= 1
            ans = max(ans, maxn)
        return ans
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # O(N)
        S = {x: 1 for x in nums}
        ans = 0
        for x in nums:
            if S[x] == 0: continue
            maxn = 1
            y = x + 1
            while y in S: S.remove(y); maxn += 1; y += 1
            y = x - 1
            while y in S: S.remove(y); maxn += 1; y -= 1
            ans = max(ans, maxn)
        return ans


print(Solution().longestConsecutive([100,4,200,1,3,2]))
print(Solution().longestConsecutive([0,3,7,2,5,8,4,6,0,1]))


