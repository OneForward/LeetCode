# leet1813

from typing import List


def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:]) for _ in range(dims[0])]


class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        A = sentence1.split()
        B = sentence2.split()
        MOD = int(10**9 + 7)
        N, M = len(A), len(B)
        if N == M: return A == B 
        if N < M: return self.areSentencesSimilar(sentence2, sentence1)

        prefixA, suffixA = [0] * (N + 1), [0] * (N + 1) 
        for i in range(N):
            prefixA[i+1] = (prefixA[i] * 10111 + hash(A[i])) % MOD 
            suffixA[N-1-i] = (suffixA[N-i] * 10111 + hash(A[N-1-i])) % MOD  
        
        prefixB, suffixB = [0] * (M + 1), [0] * (M + 1) 
        for i in range(M):
            prefixB[i+1] = (prefixB[i] * 10111 + hash(B[i])) % MOD 
            suffixB[M-1-i] = (suffixB[M-i] * 10111 + hash(B[M-1-i])) % MOD  
        D1, D2 = {}, {}
        for i in range(N, -1, -1):
            D1[prefixA[i]] = i 
        for i in range(N+1):
            D2[suffixA[i]] = i
        
        for i in range(M+1):
            if D1.get(prefixB[i], N) < D2.get(suffixB[i], 0): 
                return True
        return False
        

        
        


print(Solution().areSentencesSimilar(sentence1 = "My name is Haley", sentence2 = "My Haley"))
print(Solution().areSentencesSimilar(sentence1 = "of", sentence2 = "A lot of words"))
print(Solution().areSentencesSimilar(sentence1 = "Eating right now", sentence2 = "Eating"))
print(Solution().areSentencesSimilar(sentence1 = "Luky", sentence2 = "Lucccky"))


