# leet127

from typing import List

from collections import defaultdict

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        M = defaultdict(set)
        for word in wordList:
            edges = M[word]
            for i in range(len(word)):
                edges.add(word[:i] + '*' + word[i+1:])
        print(M)

print(Solution().ladderLength(beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"] ))


