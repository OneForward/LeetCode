# lcup21fall
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]

from collections import Counter
class Solution:
    def minimumSwitchingTimes(self, source: List[List[int]], target: List[List[int]]) -> int:
        S = Counter( x for v in source for x in v )
        T = Counter( x for v in target for x in v )

        ans = 0 
        for x, cnt in S.items():
            ans += max(cnt - T.get(x, 0), 0)
        return ans 

pprint(Solution().minimumSwitchingTimes(source = [[1,3],[5,4]], target = [[3,1],[6,5]]))
pprint(Solution().minimumSwitchingTimes(source = [[1,2,3],[3,4,5]], target = [[1,3,5],[2,3,4]]))


