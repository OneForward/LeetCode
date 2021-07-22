# leet488
# %%
from functools import lru_cache
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


from collections import Counter

class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        def shrink(board: str):
            i = 0
            for j in range(1, len(board)+1):
                if j < len(board) and board[j] == board[i]: continue
                if j - i >= 3: return shrink(board[:i] + board[j:])
                i = j
            return board
        
        @lru_cache(None)
        def dfs(board: str, hand: str):
            board = shrink(board)
            if not board: return len(hand)
            ans = -1
            for i, x in enumerate(hand):
                for j in range(len(board)): # +1?
                    ans = max(ans, dfs(board[:j] + x + board[j:], hand[:i] + hand[i+1:]))
            return ans 

        C1 = Counter(board)
        C2 = Counter(hand)
        for x, cnt in C1.items():
            if cnt + C2.get(x, 0) < 3: return -1

        ans = dfs(board, hand)
        if ans == -1: return -1 
        return len(hand) - ans
        


# pprint(Solution().findMinStep(board = "WRRBBW", hand = "RB"))
# pprint(Solution().findMinStep(board = "WWRRBBWW", hand = "WRBRW"))
# pprint(Solution().findMinStep(board = "G", hand = "GGGG"))
# pprint(Solution().findMinStep(board = "RBYYBBRRB", hand = "YRBGB"))
# pprint(Solution().findMinStep("RRWWRRW", "WR"))
# pprint(Solution().findMinStep("RRWWRRBBRR", "WB"))
pprint(Solution().findMinStep("RRYGGYYRRYYGGYRR", "GGBBB"))


