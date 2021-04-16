# leet523

from typing import List


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        sum = 0
        S = {}
        for i, x in enumerate(nums):
            sum += x 
            if k: sum %= k 
            if sum == 0 and i >= 1: return True
            if sum in S and i - S[sum] > 1: return True
            if sum not in S : 
                S[sum] = i
        return False


print(Solution().checkSubarraySum([23,2,4,6,7], k = 6))
print(Solution().checkSubarraySum([23,2,6,4,7], k = 6))
print(Solution().checkSubarraySum([23,2,0,4,7], k = 0))
print(Solution().checkSubarraySum([5,0,0], k = 0))


