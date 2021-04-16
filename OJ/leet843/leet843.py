# leet843

from typing import List

from collections import Counter, defaultdict

class Master:
    def __init__(self, wordlist, secret) -> None:
        self.wordlist = wordlist
        self.secret = secret
        self.cnt = 0
    def guess(self, word: str) -> int:
        self.cnt += 1
        print(f'cnt = {self.cnt}')
        if word not in self.wordlist: return -1
        if word == self.secret: print(f'found')
        return sum( 1 for si, ti in zip(word, self.secret) if si == ti )

from collections import Counter, defaultdict
class Solution:
    def findSecretWord(self, wordlist: List[str], master: 'Master'):
        # 数据比较水，直接贪心即可
        N = len(wordlist)
        def match(i, j):
            return sum( 1 for si, ti in zip(wordlist[i], wordlist[j]) if si == ti )

        M = defaultdict(set)
        for i in range(N):
             for j in range(i, N):
                 M[(i, match(i, j))].add(j)
        print(M)
        
        S = set(range(N))
        while S:
            i = S.pop()
            cnt = master.guess(wordlist[i])
            if cnt == 6: break
            S &= M[i, cnt]



secret = "abcczz"
wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]

master = Master(wordlist, secret)

Solution().findSecretWord(wordlist, master)


