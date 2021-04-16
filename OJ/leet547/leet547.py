# leet547

from typing import List



class Solution:


    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        P = [i for i in range(n)]
        
        def find(x):
            if x == P[x]: return x 
            P[x] = find(P[x])
            return P[x]
        
        def merge(i, j):
            P[find(i)] = find(j)
        
        for i in range(n):
            for j in range(i+1, n):
                if (isConnected[i][j]): 
                    merge(i, j)
        
        for i in range(n):  P[i] = find(i)
        return len(set(P))
        
            



# print(Solution().findCircleNum([[1,1,0],[1,1,0],[0,0,1]]))
print(Solution().findCircleNum([[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]))


