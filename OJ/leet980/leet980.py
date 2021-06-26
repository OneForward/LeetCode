# leet980
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def uniquePathsIII(self, A: List[List[int]]) -> int:
        R, C = len(A), len(A[0])
        bad = 0
        for r in range(R):
            for c in range(C):
                if A[r][c] == -1: bad += 1 
                if A[r][c] == 1:  start = (r, c); A[r][c] = -1
                if A[r][c] == 2:  end = (r, c); A[r][c] = -1
        
        ok = R * C - 1 - bad 
        ans = 0
        def dfs(path: List):
            x, y = path[-1]
            for dx, dy in ((-1,0), (1,0),(0,1),(0,-1)):
                r = x + dx; c = y + dy 
                if r >= R or r < 0 or c >= C or c < 0: continue
                if len(path) == ok and (r, c) == end:
                    nonlocal ans
                    ans += 1
                if A[r][c] != -1: 
                    path.append((r,c)); A[r][c] = -1
                    dfs(path)
                    path.pop(); A[r][c] = 0

        dfs([start])
        return ans


pprint(Solution().uniquePathsIII([[1,0,0,0],[0,0,0,0],[0,0,2,-1]]))
pprint(Solution().uniquePathsIII([[1,0,0,0],[0,0,0,0],[0,0,0,2]]))
pprint(Solution().uniquePathsIII([[0,1],[2,0]]))


