# leet140

from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        wordDict = set(wordDict)

        n = len(s)
        path, ans = [], []
        def f(lft):
            if lft == n:
                ans.append(' '.join(path))
                return
            for rht in range(lft, n):
                if s[lft:rht+1] in wordDict:
                    path.append(s[lft:rht+1])
                    f(rht+1)
                    path.pop()

        f(0)
        return ans


print(Solution().wordBreak(s = "catsanddog", wordDict = ["cat", "cats", "and", "sand", "dog"]))
print(Solution().wordBreak(s = "pineapplepenapple", wordDict = ["apple", "pen", "applepen", "pine", "pineapple"] ))
print(Solution().wordBreak(s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"] ))


