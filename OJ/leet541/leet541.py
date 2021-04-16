# leet541

from typing import List


class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        f = lambda i: s[i*k:(i+1)*k] if i % 2 else s[i*k:(i+1)*k][::-1]
        return ''.join( f(i) for i in range(len(s)//k+1) )  


print(Solution().reverseStr(s = "abcdefg", k = 2))


