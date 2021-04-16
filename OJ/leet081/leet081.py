# leet081

from typing import List

from bisect import bisect_left
class Solution:
    def search(self, A: List[int], x: int) -> bool:
        lft, rht = 0, len(A)
        x0 = A[0]
        while rht > 1 and A[rht-1] == x0: rht -= 1
        while lft < rht:
            mid = (lft + rht) // 2 
            if A[mid] < x0: rht = mid 
            else: lft = mid + 1
        if x >= x0:  lft, rht = 0, lft 
        else: lft, rht = lft, len(A) 
        pos = bisect_left(A, x, lft, rht)
        return pos < rht and A[pos] == x


print(Solution().search([1],  1))
print(Solution().search([1,3],  0))
print(Solution().search([1,0,1,1,1],  0))
print(Solution().search([2,5,6,0,0,1,2],  0))
print(Solution().search([2,5,6,0,0,1,2],  3))


