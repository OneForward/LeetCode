# leet746

from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        prev, curr = 0, 0
        for i in range(1, len(cost)):
            newcost = min(prev + cost[i-1], curr + cost[i])
            prev, curr = curr, newcost 
        return curr


print(Solution().minCostClimbingStairs(cost = [10, 15, 20]))
print(Solution().minCostClimbingStairs(cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]))


