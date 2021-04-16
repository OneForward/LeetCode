# leet1503

from typing import List


class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        # 交换方向对问题等效没有影响
        return max(n-min(right, default=n), max(left, default=0))


print(Solution().getLastMoment(n = 4, left = [4,3], right = [0,1]))


