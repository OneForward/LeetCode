# leet766

from typing import List


class Solution1:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:

        R, C = len(matrix), len(matrix[0])
        for d in range(C-1):
            x = matrix[0][d]
            for r in range(min(R, C-d)):
                if matrix[r][r+d] != x: return False
        for d in range(1, R-1):
            x = matrix[d][0]
            for r in range(d, min(R, C+d)):
                if matrix[r][r-d] != x: return False
        return True

class Solution2:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:

        R, C = len(matrix), len(matrix[0])
        for d in range(-(R-2), C-1):
            x = matrix[max(0, -d)][max(0, d)]
            for r in range(max(0, -d), min(R, C-d)):
                if matrix[r][r+d] != x: return False
        return True

class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:

        R, C = len(matrix), len(matrix[0])
        for r in range(R-1):
            for c in range(C-1):
                if matrix[r][c] != matrix[r+1][c+1]: return False
        return True




print(Solution().isToeplitzMatrix(matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]))
print(Solution().isToeplitzMatrix(matrix = [[1,2],[2,2]]))
print(Solution().isToeplitzMatrix(matrix = [[83],[64],[57]]))


