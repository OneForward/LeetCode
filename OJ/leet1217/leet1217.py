from typing import List 
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        ans = [0, 0]
        for pos in chips:
            ans[pos%2] += 1
        return min(ans)
        
chips = [2, 2, 2, 3, 3]
counter = [0] * max(chips)
for pos in chips:
    counter[pos-1] += 1
# counter = [0, 3, 2]

counter = [1, 6, 8, 0, 5]

