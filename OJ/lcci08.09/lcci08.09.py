# lcci08.09
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def f(n):
            if n == 1: return set(("()", ))
            prev = f(n-1)
            new = set()
            for s in prev:
                for i in range(len(s)):
                    lft, rht = 0, 0
                    for j in range(i, len(s)):
                        if s[j] == '(': lft += 1
                        else: rht += 1
                        if lft == rht:
                            new.add(f'{s[:i]}({s[i:j]}){s[j:]}')
                new.add(f'{s}()')
            return new 
        return list(f(n))

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def f(s, lft, rht):
            if lft > n or lft < rht: return 
            if lft == rht == n: 
                ans.append(s)
                return
            f(s + '(', lft + 1, rht)
            f(s + ')', lft, rht + 1)
        f('', 0, 0)
        return ans


pprint(Solution().generateParenthesis(4))
pprint(Solution().generateParenthesis(3))
pprint(Solution().generateParenthesis(2))
pprint(Solution().generateParenthesis(1))



# %%
my = ["(((())))","()((()))","((()))()","(()(()))","()()(())","((())())","()(())()","(())()()","((()()))","()(()())","(()())()","(()()())","()()()()"]
ans = ["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
set(ans) - set(my)

# %%
