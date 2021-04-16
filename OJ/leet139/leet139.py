# leet139

from typing import List



class Solution1:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # TLE
        def recursive(s: str, wordDict: List[str]) -> bool:
            if len(s) == 0: return True

            for word in wordDict:
                if len(word) > len(s): continue 
                if s.startswith(word) and recursive(s[len(word):], wordDict):
                    return True
            return False
        return recursive(s, wordDict) 

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # 56ms, 完全背包问题, 注意这个问题的 v 和 w 的循环顺序
        f = [False] * (len(s) + 1)
        f[0] = True
        for v in range(1, len(s)+1):
            for w in wordDict:
                if v >= len(w):
                    if s[len(s)-v:len(s)-v+len(w)] == w:
                        f[v] |= f[v-len(w)]
        return f[len(s)]

print(Solution().wordBreak(s = "leetcode", wordDict = ["leet", "code"]))
print(Solution().wordBreak(s = "applepenapple", wordDict = ["apple", "pen"]))
print(Solution().wordBreak(s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]))
print(Solution().wordBreak("cars", ["car","ca","rs"]))



