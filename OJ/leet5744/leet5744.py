# leet5744
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        C = len(box[0])
        def gap(L, i):
            while i < len(L) and L[i] != '*': i += 1
            return i

        for row in box:
            start = 0
            while 1:
                g = gap(row, start)
                p = g - 1 
                for i in range(g-1, start-1, -1):
                    if row[i] == '#': 
                        row[p] = row[i]; p -= 1
                for i in range(start, p+1):
                    row[i] = '.'
                if g == len(row): break
                start = g + 1 
        return [[ row[i] for row in reversed(box)] for i in range(C) ]


pprint(Solution().rotateTheBox(box = [
            ["#","#","*",".","*","."],
            ["#","#","#","*",".","."],
            ["#","#","#",".","#","."]]))
pprint(Solution().rotateTheBox(box = [["#",".","*","."], ["#","#","*","."]]))
pprint(Solution().rotateTheBox([["#",".","#"]]))


