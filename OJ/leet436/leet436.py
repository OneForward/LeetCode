# leet436
# %%
from bisect import bisect, bisect_left, bisect_right
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        lft, rht, index = list(zip(*sorted((lft, rht, index) for index, (lft, rht) in enumerate(intervals))))
        
        f = lambda i: index[i] if i < len(index) else -1
        return [  f(bisect_left(lft, r))  for _, r in intervals]



pprint(Solution().findRightInterval(intervals = [[1,2]]))
pprint(Solution().findRightInterval(intervals = [[3,4],[2,3],[1,2]]))
pprint(Solution().findRightInterval(intervals = [[1,4],[2,3],[3,4]]))


