# lcup21fall
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]

class Solution:
    def maxmiumScore(self, cards: List[int], M: int) -> int:
        cards = sorted(cards, reverse=True)
        S = sum(cards[:M])
        odd1 = [ x for x in cards[:M] if x % 2 ]
        even1 = [ x for x in cards[:M] if x % 2 == 0 ]
        odd2 = [ x for x in cards[M:] if x % 2 ]
        even2 = [ x for x in cards[M:] if x % 2 == 0 ]
        if len(odd1) % 2 == 0: return S
        delta = -S
        if len(odd1) and len(even2): delta = max(delta, even2[0] - odd1[-1])
        if len(odd2) and len(even1): delta = max(delta, odd2[0] - even1[-1])
        return delta + S 




pprint(Solution().maxmiumScore(  [1,2,8,9],  3))
pprint(Solution().maxmiumScore(  [3,3,1],  1))


