# leet554

from typing import List


def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:]) for _ in range(dims[0])]

from collections import defaultdict
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        Counter = defaultdict(int)
        for L in wall:
            sum = 0
            for x in L[:-1]:
                sum += x 
                Counter[sum] += 1
        # print(Counter) 
        if not Counter: return len(wall)
        ans = max(Counter.values())
        return len(wall) - ans 


print(Solution().leastBricks(wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]))
print(Solution().leastBricks(wall = [[1],[1],[1]]))


