# lcup21fall
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]

class Solution:
    def flipChess(self, chessboard: List[str]) -> int: 
        ...




pprint(Solution().flipChess( ["....X.","....X.","XOOO..","......","......"] ))
pprint(Solution().flipChess( [".X.",".O.","XO."] ))
pprint(Solution().flipChess( [".......",".......",".......","X......",".O.....","..O....","....OOX"] ))


