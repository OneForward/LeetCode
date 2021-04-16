# leet648
# 推荐 Trie 的一行 Pythonic 写法

from typing import List


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        words = sentence.split()
        Trie = {}

        for word in dictionary:
            node = Trie
            for ch in word:
                if ch not in node: node[ch] = {}
                node = node[ch] 
            node['$'] = word 
        
        ans = []
        for word in words:
            node = Trie
            for ch in word:
                if '$' in node: 
                    ans.append(node['$']); break 
                if ch not in node: 
                    ans.append(word); break 
                node = node[ch] 
            else:
                ans.append(word)
        return ' '.join(ans)

from collections import defaultdict
from functools import reduce   
class SolutionOfficial(object):
    def replaceWords(self, roots, sentence):
        Trie = lambda: defaultdict(Trie)
        trie = Trie()
        END = True

        for root in roots:
            reduce(dict.__getitem__, root, trie)[END] = root

        def replace(word):
            cur = trie
            for letter in word:
                if letter not in cur or END in cur: break
                cur = cur[letter]
            return cur.get(END, word)

        return " ".join(map(replace, sentence.split()))





print(Solution().replaceWords(dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery" ))
print(Solution().replaceWords( dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs" ))
print(Solution().replaceWords( dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa" ))
print(Solution().replaceWords( dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"  ))
print(Solution().replaceWords( dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"  ))


