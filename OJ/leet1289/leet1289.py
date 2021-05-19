# leet1289
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        R, C = len(A), len(A[0])
        f = init((R+1, C), 0)

        for r in range(R):
            for c in range(C):
                f[r+1][c] = 1<<31
                for c0 in range(C):
                    if c0 == c: continue
                    f[r+1][c] = min(f[r+1][c], f[r][c0])
                f[r+1][c] += A[r][c]
        return min(f[R])


pprint(Solution().minFallingPathSum([[1,2,3],[4,5,6],[7,8,9]]))


