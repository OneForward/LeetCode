# leet324

from typing import List


class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums[0::2], nums[1::2] = sorted(nums)[:len(nums)-len(nums)//2][::-1], sorted(nums)[len(nums)-len(nums)//2:][::-1]
        return nums


 


print(Solution().wiggleSort([1,5,1,1,6,4]))
print(Solution().wiggleSort([1,3,2,2,3,1]))


