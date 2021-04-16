# leet208

from typing import List


class Node:
    def __init__(self, isleaf=False) -> None:
        self.next = {}
        self.isleaf = isleaf

class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node()


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        p = self.root
        for ch in word:
            if ch not in p.next: p.next[ch] = Node()
            p = p.next[ch]
        p.isleaf = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        p = self.root
        for ch in word:
            if ch not in p.next: return False
            p = p.next[ch]
        return p.isleaf 


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        p = self.root
        for ch in prefix:
            if ch not in p.next: return False
            p = p.next[ch]
        return True


trie = Trie()

print(trie.insert("apple"))
print(trie.search("apple"))
print(trie.search("app"))
print(trie.startsWith("app"))
print(trie.insert("app"))
print(trie.search("app"))



