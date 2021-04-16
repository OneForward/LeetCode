# leet724

from typing import List


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums) 
        ans, lftSum = 0, 0
        for ans in range(len(nums)):
            if ans:
                lftSum += nums[ans-1]
                if total == lftSum * 2 + nums[ans]: return ans 
            elif ans == 0 and total == nums[0]: return 0
        return -1
        


print(Solution().pivotIndex(nums = [1, 7, 3, 6, 5, 6]))
print(Solution().pivotIndex(nums = [1, 2, 3]))


