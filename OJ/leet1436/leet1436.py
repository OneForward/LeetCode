# leet1436
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        first = set(x[0] for x in paths)
        second = set(x[1] for x in paths)
        return list(second - first)[0]


pprint(Solution().destCity([["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]))
pprint(Solution().destCity([["B","C"],["D","B"],["C","A"]]))
pprint(Solution().destCity([["A","Z"]]))


