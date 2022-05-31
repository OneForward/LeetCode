# leet1021
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        start = 0
        f = 0
        ans = ''
        for i, ch in enumerate(s):
            if ch == ')': f -= 1 
            else: f += 1
            if f == 0: ans += s[start + 1: i]; start = i + 1

        return ans


pprint(Solution().removeOuterParentheses("(()())(())"))
pprint(Solution().removeOuterParentheses("(()())(())(()(()))"))
pprint(Solution().removeOuterParentheses( "()()"))


