# weekly-245
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]

class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        N = len(triplets)
        I = [True] * N
        for i, p in enumerate(triplets): 
            if p == target: return True

            for x, y in zip(p, target):
                if x > y: I[i] = False

        if not any(I): return False
        p = list(max(triplets[i][j] for i in range(N) if I[i]) for j in range(3))
        return p == target

pprint(Solution().mergeTriplets(triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]))
pprint(Solution().mergeTriplets(triplets = [[1,3,4],[2,5,8]], target = [2,5,8]))
pprint(Solution().mergeTriplets(triplets = [[2,5,3],[2,3,4],[1,2,5],[5,2,3]], target = [5,5,5]))
pprint(Solution().mergeTriplets(triplets = [[3,4,5],[4,5,6]], target = [3,2,5]))
pprint(Solution().mergeTriplets([[2,6,6],[10,5,1],[8,9,2],[7,2,9],[5,10,6]]
,[10,6,6]))



# %%
