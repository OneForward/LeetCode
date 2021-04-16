# leet839

from typing import List


class Solution:
    def numSimilarGroups(self, S: List[str]) -> int:
        def isok(s1, s2):
            cnt = 0
            f1, f2 = "", ""
            for x, y in zip(s1, s2):
                if x != y:
                    cnt += 1
                    if cnt == 1: f1 = x + y
                    if cnt == 2: f2 = y + x
                    if cnt > 2: return False
            return f1 == f2
        def find(i):
            if i == M[i]: return i 
            return find(M[i])
        def merge(i, j):
            pi, pj = find(i), find(j)
            if pi == pj: return 
            M[pj] = pi
        n = len(S)
        M = [i for i in range(n)]
        for i in range(n):
            for j in range(i):
                if isok(S[j], S[i]): 
                    merge(i, j)
        
        cnt = 0
        for i, pi in enumerate(M):
            if i == pi: cnt += 1
        return cnt


print(Solution().numSimilarGroups(["ajdidocuyh","djdyaohuic","ddjyhuicoa","djdhaoyuic","ddjoiuycha","ddhoiuycja","ajdydocuih","ddjiouycha","ajdydohuic","ddjyouicha"]))
print(Solution().numSimilarGroups(["jmijc","imjjc","jcijm","cmijj","mijjc"]))


