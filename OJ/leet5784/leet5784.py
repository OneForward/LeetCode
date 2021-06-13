# weekly-245
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]

from collections import defaultdict
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        C = defaultdict(int)
        for word in words:
            for x in word: C[x] += 1
        for cnt in C.values():
            if cnt % len(words): return False
        return True


pprint(Solution().solver())


