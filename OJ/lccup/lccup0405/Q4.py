# lccup0405

from typing import List

class Solution:
    def escapeMaze(self, maze: List[List[str]]) -> bool:
        # state 0: normal,  1: Temp ,  2: Forever
        Normal, Temp, Forever = 0, 1, 2
        DIR = ((0, 0), (0, 1), (0, -1), (1, 0), (-1, 0))
        R, C = len(maze[0]), len(maze[0][0])
        M = set()
        T = len(maze)
        def dfs(x, y, time, state, x0=0, y0=0):
            if time == T: return x == R-1 and y == C-1
            if (x, y, time, state, x0, y0) in M: return False
            for dx, dy in DIR:
                r, c = x + dx, y + dy 
                if r < 0 or r >= R or c < 0 or c >= C: continue
                if maze[time][r][c] == '.': 
                    if dfs(r, c, time + 1, state, x0, y0): return True 
                
                elif state == Forever:
                    if (r, c) == (x0, y0) and dfs(r, c, time + 1, Forever, r, c): return True

                elif state == Normal:
                    if dfs(r, c, time + 1, Temp): return True  
                    if dfs(r, c, time + 1, Forever, r, c): return True  
            M.add((x, y, time, state, x0, y0))
            return False
        return dfs(0, 0, 1, Normal)      





print(Solution().escapeMaze(maze = [[".#.","#.."],["...",".#."],[".##",".#."],["..#",".#."]]))
print(Solution().escapeMaze(maze = [[".#.","..."],["...","..."]]))
print(Solution().escapeMaze(maze = [["...","...","..."],[".##","###","##."],[".##","###","##."],[".##","###","##."],[".##","###","##."],[".##","###","##."],[".##","###","##."]]))


