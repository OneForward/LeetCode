from typing import List
from collections import Counter
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        C = Counter(nums)
        return [k for k, v in C.items() if v > len(nums) / 3]

print(Solution().majorityElement([1,1,1,3,3,2,2,2]))