# leet1658

from typing import List


class Solution:
    def minOperations1(self, nums: List[int], x: int) -> int:
        # O(N^2)
        def isOk(k: int) -> bool:
            # checkout if window_size = k is ok
            window = sum(nums[-k:])
            if window == x: return True
            for i in range(k):
                window += nums[i] - nums[i-k]
                if window == x: return True
            return False

        for k in range(1, len(nums)+1):
            if isOk(k): return k 
        return -1
    
    def minOperations(self, nums: List[int], x: int) -> int:
        # 转化为 求解最长的、和为 sum(nums)-x 的字串 问题
        # 使用普通的 sliding window 即可解决, o(N)
        target = sum(nums) - x 
        if target < 0: return -1 

        curSum = 0
        lft = 0
        ans = -1
        for rht in range(len(nums)):
            curSum += nums[rht]
            while curSum > target: curSum -= nums[lft]; lft += 1
            if curSum == target: ans = max(ans, rht - lft + 1)
        if ans == -1: return -1
        return len(nums) - ans


print(Solution().minOperations(nums = [1,1,4,2,3], x = 5))
print(Solution().minOperations(nums = [5,6,7,8,9], x = 4))
print(Solution().minOperations(nums = [3,2,20,1,1,3], x = 10))
print(Solution().minOperations([1000,1,1,2,3], 1004))
print(Solution().minOperations([8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309],134365))


