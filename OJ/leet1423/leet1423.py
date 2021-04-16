# leet1423

from typing import List


class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        # O(K)
        ans = point = sum(cardPoints[:k])
        for i in range(1, k+1):
            point = point - cardPoints[k-i] + cardPoints[-i]
            ans = max(ans, point)
        return ans 


print(Solution().maxScore(cardPoints = [1,2,3,4,5,6,1], k = 3))
print(Solution().maxScore(cardPoints = [2,2,2], k = 2))
print(Solution().maxScore(cardPoints = [9,7,7,9,7,7,9], k = 7))
print(Solution().maxScore(cardPoints = [1,1000,1], k = 1))
print(Solution().maxScore(cardPoints = [1,79,80,1,1,1,200,1], k = 3))


