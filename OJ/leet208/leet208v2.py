# leet208

from typing import List


from collections import defaultdict
from functools import reduce

END = 0
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        Trie = lambda : defaultdict(Trie)
        self.trie = Trie()


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        reduce(dict.__getitem__, word, self.trie)[END] = word

    def __find(self, word: str) :
        
        p = self.trie
        for ch in word:
            if ch not in p: return None
            p = p[ch]
        return p  

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        return (p := self.__find(word)) is not None and END in p


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        return self.__find(prefix) is not None


trie = Trie()

print(trie.insert("apple"))
print(trie.search("apple"))
print(trie.search("app"))
print(trie.startsWith("app"))
print(trie.insert("app"))
print(trie.search("app"))



