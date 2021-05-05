# leet640
# %%
from typing import List


def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]

import re 
class Solution:
    def solveEquation(self, equation: str) -> str:
        lft, rht = equation.split('=')
        def fetch(s):
            k, b = 0, 0
            re.split(r'+|-', lft)
        ... 


print(Solution().solveEquation("x+5-3+x=6+x-2"))
print(Solution().solveEquation("x=x"))
print(Solution().solveEquation("2x=x"))
print(Solution().solveEquation("2x+3x-6x=x+2"))
print(Solution().solveEquation("x=x+2"))



# %%
equation = "2x+3x-6x=x+2-5+4"
lft, rht = equation.split('=')

lft
re.split(r'\+|-', lft)
