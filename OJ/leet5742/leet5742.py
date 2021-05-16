# leet5742
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def sortSentence(self, s: str) -> str:
        words = s.split()
        vs = [int(s[-1] ) for s in words]
        words = [ s[:-1] for s in words ]
        return ' '.join(x for _, x in sorted(zip(vs, words)))


print(Solution().sortSentence("is2 sentence4 This1 a3"))
print(Solution().sortSentence("Myself2 Me1 I4 and3"))


