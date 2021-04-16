# leet1178

from typing import List

from collections import defaultdict
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        D = defaultdict(int)
        for word in words:
            x = 0
            for ch in word:
                x |= (1 << (ord(ch) - ord('a')))
            D[x] += 1
        
        ans = []
        for p in puzzles:
            x = 0
            for ch in p:
                x |= (1 << (ord(ch) - ord('a')))
            first = (1 << (ord(p[0]) - ord('a')))
            mask = x 
            cnt = 0
            while x:
                if x in D and x & first: cnt += D[x]
                x = (x - 1) & mask
            ans.append(cnt)
        return ans




print(Solution().findNumOfValidWords(words = ["aaaa","asas","able","ability","actt","actor","access"], 
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"] ))


