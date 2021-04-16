from typing import *

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix: return []

        R, C = len(matrix), len(matrix[0])
        RC = R*C 
        ans = []
        k = 0
        while True:
            for c in range(k, C-k):
                ans.append( matrix[k][c] )
            if len(ans) == RC: break
            
            for r in range(k+1, R-k):
                ans.append( matrix[r][C-k-1] )
            if len(ans) == RC: break
            
            for c in range(C-k-2, k-1, -1):
                ans.append( matrix[R-k-1][c] )
            if len(ans) == RC: break
            
            for r in range(R-k-2, k, -1):
                ans.append( matrix[r][k] )
            if len(ans) == RC: break
            
            k += 1
        return ans








m = [
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]

print(Solution().spiralOrder(m))