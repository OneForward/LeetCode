# lcof38
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def permutation(self, s: str) -> List[str]:
        N = len(s)
        s = sorted(s)
        path = []
        used = [False]  * N 
        ans = []
        def dfs():
            if len(path) == N:
                ans.append(''.join(path))
                return 
            
            for i in range(N):
                if used[i]: continue
                if i > 0 and s[i] == s[i-1] and not used[i-1]: continue

                used[i] = True
                path.append(s[i])
                dfs()
                path.pop()
                used[i] = False
        
        dfs()
        return ans


pprint(Solution().permutation("caba"))


