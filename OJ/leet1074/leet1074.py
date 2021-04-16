# leet1074

from typing import List

from copy import deepcopy

class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        n, m = len(matrix), len(matrix[0])

        rowAcc = deepcopy(matrix)
        for row in rowAcc:
            for i in range(1, m):
                row[i] += row[i-1]
        
        ans = 0
        for x1 in range(m):
            for x2 in range(x1, m):
                for y1 in range(n):
                    curSum = 0
                    for y2 in range(y1, n):
                        curSum += rowAcc[y2][x2] - rowAcc[y2][x1] + matrix[y2][x1]
                        if curSum == target: 
                            ans += 1
        return ans
print(Solution().numSubmatrixSumTarget(matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0))
print(Solution().numSubmatrixSumTarget(matrix = [[1,-1],[-1,1]], target = 0))


