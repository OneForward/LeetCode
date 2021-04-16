# leet299

from typing import List

from collections import Counter, defaultdict
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        S = Counter(secret)
        G = defaultdict(int, Counter(guess))
        A, B = 0, 0
        for si, gi in zip(secret, guess):
            if si == gi: A += 1
        for si in S:
            B += min(G[si], S[si])
        return f'{A}A{B-A}B' 


print(Solution().getHint(secret = "1807", guess = "7810"))
print(Solution().getHint(secret = "1123", guess = "0111"))


