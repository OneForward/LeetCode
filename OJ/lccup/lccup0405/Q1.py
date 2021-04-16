# lccup0405

from typing import List


class Solution:
    def purchasePlans(self, nums: List[int], target: int) -> int:
        A = nums
        n = len(A)
        A.sort()
        lft, rht = 0, n - 1
        ans = 0
        for lft in range(n):
            x = A[lft]
            while rht > lft and A[rht] + x > target: rht -= 1
            if rht == lft: break
            ans += rht - lft 
        return ans % int(1e9 + 7)


print(Solution().purchasePlans(nums = [2,5,3,5], target = 6))
print(Solution().purchasePlans(nums = [2,2,1,9], target = 10))


