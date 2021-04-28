# lcci08.04

from typing import List


def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:]) for _ in range(dims[0])]

from copy import deepcopy
class Solution:
    def subsets(self, A: List[int]) -> List[List[int]]:
        A.sort()
        N = len(A)
        ans = [[]]
        lft = 0
        while lft < N:
            x = A[lft]
            rht = lft + 1 
            while rht < N and A[rht] == A[rht-1]: rht += 1
            no = deepcopy(ans)
            for v in no:
                for _ in range(lft, rht):
                    v.append(x)
                    ans.append(v.copy())
            lft = rht
        return ans



print(Solution().subsets([1,2,3]))
print(Solution().subsets([1,2,3,3]))
print(Solution().subsets([1,2,3,4]))


