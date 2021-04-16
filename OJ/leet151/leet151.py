# leet151

from typing import List


class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join( reversed( [si for si in s.split(' ') if si]) )


print(Solution().reverseWords("  hello world  "))


