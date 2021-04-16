# leet399

from typing import List


class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        P, D = {}, {}
        def find(x, insert):
            if x not in P:
                if insert: P[x] = None; D[x] = 1.; return (x, 1.)
                else: return (None, -1.)
            if not P[x]: return (x, 1.)
            parent, dist = find(P[x], insert)
            P[x] = parent
            D[x] *= dist
            return (parent, D[x])
        
        for ((x, y), d) in zip(equations, values):
            rx, dx = find(x, True)
            ry, dy = find(y, True)
            if rx == ry: continue
            P[ry], D[ry] = rx, d * dx / dy 
        
        ans = []
        for (x, y) in queries:
            rx, dx = find(x, False)
            ry, dy = find(y, False)
            if not rx or rx != ry: ans.append(-1.)
            else: ans.append(dy / dx)
        return ans 

        
print(Solution().calcEquation(equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]))


