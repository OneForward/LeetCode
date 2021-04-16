# leet895

from typing import List

from collections import defaultdict

class FreqStack:

    def __init__(self):
        self.freq = defaultdict(int)
        self.group = defaultdict(list) 
        self.maxfreq = 0

    def push(self, x: int) -> None:
        self.freq[x] += 1
        f = self.freq[x]
        self.maxfreq = max(f, self.maxfreq)
        self.group[f].append(x)

    def pop(self) -> int:
        x = self.group[self.maxfreq].pop()
        self.freq[x] -= 1
        if not self.group[self.maxfreq]:
            self.maxfreq -= 1
        return x


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
        ... 


# print(Solution().solver())


