# leet994

from typing import List


from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        Q = deque()
        R, C = len(grid), len(grid[0])
        for x in range(R):
            for y in range(C):
                if grid[x][y] == 2: 
                    Q.append((x, y))

        DIR = ((0, 1), (0, -1), (-1, 0), (1, 0))
        time = -1
        while Q:
            time += 1
            for _ in range(len(Q)):
                x, y = Q.popleft()
                for dx, dy in DIR:
                    r, c = x + dx, y + dy 
                    if r >= 0 and c >= 0 and r < R and c < C and grid[r] [c] == 1: 
                        grid[r][c] = 2
                        Q.append((r, c))
        if any(1 in row for row in grid): return -1
        return max(time, 0)


print(Solution().orangesRotting([[1],[2],[1],[2]]))
print(Solution().orangesRotting([[2,1,1],[1,1,0],[0,1,1]]))
print(Solution().orangesRotting([[2,1,1],[0,1,1],[1,0,1]]))
print(Solution().orangesRotting([[0,2]]))
print(Solution().orangesRotting([[0]]))


