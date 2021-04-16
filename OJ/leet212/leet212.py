# leet212

from typing import List

class Trie:
    def __init__(self) -> None:
        self.next = {}
        self.isleaf = '' 
    
    def addword(self, word):
        p = self 
        for ch in word:
            if ch not in p.next: p.next[ch] = Trie()
            p = p.next[ch]
        p.isleaf = word


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        for word in words: trie.addword(word)

        ans = []
        n, m = len(board), len(board[0])
        def find(x, y, parent):
            if x < 0 or y < 0 or x >= n or y >= m: return 

            ch = board[x][y]
            if ch not in parent.next: return 

            curNode = parent.next[ch]
            if curNode.isleaf: 
                ans.append(curNode.isleaf); 
                curNode.isleaf = ''

            board[x][y] = '#'
            for nx, ny in ((x+1, y), (x-1, y), (x, y+1), (x, y-1)):
                find(nx, ny, curNode)
            board[x][y] = ch 

            # 以下这一句是提速的灵魂，修改树结构，减少分支
            if not curNode.next:  parent.next.pop(ch)

        for x in range(n):
            for y in range(m):
                find(x, y, trie)
        return ans


print(Solution().findWords(board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"] ))
print(Solution().findWords([["o","a","b","n"],["o","t","a","e"],["a","h","k","r"],["a","f","l","v"]], ["oa","oaa"] ))
print(Solution().findWords(board = [["a","b"],["c","d"]], words = ["abcb"]))
print(Solution().findWords([["a","a"]], ["aaa"]))
print(Solution().findWords([["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], ["oath","pea","eat","rain","hklf", "hf"]))


