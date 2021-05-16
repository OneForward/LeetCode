# leet5743
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]

class Solution:
    def memLeak(self, memory1: int, memory2: int) -> List[int]:
        for x in range(1<<17):
            if x > max(memory1, memory2): break
            if memory1 >= memory2: memory1 -= x 
            else: memory2 -= x 
        return [x, memory1, memory2]


print(Solution().memLeak(2,2))
print(Solution().memLeak(8, 11))


