# lcci17.07
# %%
import sys
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]

class UnionSet:
    def __init__(self, names, cnt) -> None:
        self.names = names 
        self.P = [i for i in range(len(cnt))] 
        self.cnt = cnt

    def find(self, x):
        P = self.P 
        if P[x] == x: return x 
        P[x] = self.find(P[x])
        return P[x]

    def merge(self, x, y):
        P, names, cnt = self.P , self.names, self.cnt
        rx, ry = self.find(x), self.find(y)
        if rx == ry: return rx 
        if names[rx] > names[ry]: rx, ry = ry, rx
        cnt[rx] += cnt[ry]
        P[ry] = rx
        return rx 


class Solution:
    def trulyMostPopular(self, oldnames: List[str], synonyms: List[str]) -> List[str]:
        names, counter = [], []
        for name in oldnames:
            pos = name.find('(')
            name, cnt = name[:pos], int(name[pos+1:-1])
            names.append(name)
            counter.append(cnt)
        S = UnionSet(names, counter)
        M = {name: i for i, name in enumerate(names)}
        for name in synonyms:
            pos = name.find(',')
            x, y = name[1:pos], name[pos+1:-1]
            if x not in M: M[x] = len(names); S.P.append(len(names)); names.append(x); counter.append(0); 
            if y not in M: M[y] = len(names); S.P.append(len(names)); names.append(y); counter.append(0); 
            S.merge(M[x], M[y])
        ans = []
        for i, (p, cnt) in enumerate(zip(S.P, S.cnt)):
            if i != p: continue
            ans.append(f"{names[i]}({cnt})")
        return ans


print(Solution().trulyMostPopular( ["John(15)","Jon(12)","Chris(13)","Kris(4)","Christopher(19)"], synonyms = ["(Jon,John)","(John,Johnny)","(Chris,Kris)","(Chris,Christopher)"]))
print(Solution().trulyMostPopular(["a(10)","c(13)"], ["(a,b)","(c,d)","(b,c)"]))


