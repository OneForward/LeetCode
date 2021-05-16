# leet5712
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def sumOfFlooredPairs(self, A: List[int]) -> int:
        
        ...


print(Solution().sumOfFlooredPairs( [2,5,9]))
print(Solution().sumOfFlooredPairs([7,7,7,7,7,7,7]))


