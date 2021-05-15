# lcci08.12
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]

class Solution:
    def solveNQueens(self, N: int) -> List[List[str]]:
        s = '.' * (N-1)
        ans = []
        def f(L):
            n = len(L)
            if n == N: 
                ans.append([f'{s[:x]}Q{s[x:]}' for x in L])
                return
            for x in range(N):
                for r, c in enumerate(L):
                    if c == x or r + c == x + n or r - c == n - x: break
                else:
                    f(L + [x])
        f([])
        return ans

class Solution:
    def solveNQueens(self, N: int) -> List[List[str]]:
        s = '.' * (N-1)
        ans = []
        def f(L):
            n = len(L)
            if n == N: 
                ans.append([f'{s[:x]}Q{s[x:]}' for x in L])
                return
            for x in range(N):
                for r, c in enumerate(L):
                    if c == x or r + c == x + n or r - c == n - x: break
                else:
                    L.append(x)
                    f(L)
                    L.pop()
        f([])
        return ans


print(Solution().solveNQueens(4))


