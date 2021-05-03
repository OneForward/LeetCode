# lcci17.22

from typing import List


def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:]) for _ in range(dims[0])]

from collections import defaultdict
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[str]:
        hash = lambda x: x 
        M = defaultdict(set)
        for word in wordList + [beginWord]:
            x = hash(word)
            for i in range(len(word)):
                y = hash(word[:i] + '*' + word[i+1:])
                M[x].add(y)
                M[y].add(x)
        # print(M)

        start, dest = hash(beginWord), hash(endWord)
        visited = {}
        for x in M.keys(): visited[x] = False

        v = []
        def f(s):
            v.append(s)
            if s == dest: return True
            visited[s] = True
            for p in M[s]:
                if not visited[p] and f(p): return True
            v.pop()
            return False 
        
        f(start)
        return [v[i] for i in range(len(v)) if i % 2 == 0]

from collections import defaultdict
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[str]:
        wordList.append(beginWord)
        pos = {}
        M = defaultdict(list)
        for word in wordList:
            x = hash(word)
            pos[x] = word
            for i in range(len(word)):
                y = hash(word[:i] + '*' + word[i+1:])
                pos[y] = word[:i] + '*' + word[i+1:]
                M[x].append(y)
                M[y].append(x)
        # print(M)

        start, dest = hash(beginWord), hash(endWord)
        visited = {}
        for x in M.keys(): visited[x] = False

        v = []
        def f(s):
            v.append(s)
            if s == dest: return True
            visited[s] = True
            for p in M[s]:
                if not visited[p] and f(p): return True
            v.pop()
            return False 
        
        f(start)
        return [pos[v[i]] for i in range(len(v)) if i % 2 == 0]




from collections import defaultdict
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[str]:
        wordList.append(beginWord)
        M, pos = [], {}
        for word in wordList:
            if word not in pos: pos[word] = x = len(M); M.append([])
            x = pos[word]
            for i in range(len(word)):
                mid = word[:i] + '*' + word[i+1:]
                if mid not in pos: pos[mid] = len(M); M.append([])
                y = pos[mid]
                M[x].append(y)
                M[y].append(x)

        if endWord not in pos: return []

        words = {i: word for word, i in pos.items()}
        start, dest = pos[beginWord], pos[endWord]
        visited = [False] * len(M)

        v = []
        def f(s):
            v.append(s)
            if s == dest: return True
            visited[s] = True
            for p in M[s]:
                if not visited[p] and f(p): return True
            v.pop()
            return False 
        
        f(start)
        return [words[v[i]] for i in range(len(v)) if i % 2 == 0]



# print(Solution().findLadders(   beginWord = "hit",
#                                 endWord = "cog",
#                                 wordList = ["hot","dot","dog","lot","log","cog"] ))
# print(Solution().findLadders(   beginWord = "hit",
#                                 endWord = "cog",
#                                 wordList = ["hot","dot","dog","lot","log"] ))
print(Solution().findLadders(   "hot",
                                "dog", 
                                ["hot","cog","dog","tot","hog","hop","pot","dot"] ))


