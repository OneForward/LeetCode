# leet557

from typing import List


class Solution:
    def reverseWords(self, s: str) -> str:
        return ' ' .join( si[::-1] for si in s.split(' ') )


print(Solution().reverseWords("Let's take LeetCode contest"))


