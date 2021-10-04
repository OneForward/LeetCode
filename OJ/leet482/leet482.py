# leet482
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = s.upper()
        s = ''.join(s.split('-'))
        prev = len(s) % k 
        if prev == 0:
            s = '-'.join(s[i:i+k] for i in range(prev, len(s), k))
        else:
            s = '-'.join([s[:prev]] + [s[i:i+k] for i in range(prev, len(s), k)])
        return s 


pprint(Solution().licenseKeyFormatting("5F3Z-2e-9-w",  4))
pprint(Solution().licenseKeyFormatting("2-5g-3-J",  2))


