from typing import List
from collections import Counter

def issubseq(key, s):
    ci = -1
    for ki in key:
        ci = s.find(ki, ci + 1)
        if ci == -1: return False
    return True 

class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        C = Counter(strs)
        keys = sorted(C.keys(), key=len, reverse=True)

        S = set()
        for key in keys:
            if C[key] == 1:
                for s in S:
                    if issubseq(key, s):
                        break
                else:
                    return len(key)
            S.add(key)
        return -1

sol = Solution()
print(sol.findLUSlength(["aa", "aaa", "aaa", "bb"]))