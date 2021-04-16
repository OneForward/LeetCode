# leet347

from typing import List

from collections import Counter 

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        C = Counter(nums)
        return [x for x, _ in C.most_common(k)]
         


print(Solution().topKFrequent(nums = [1,1,1,2,2,3], k = 2))


