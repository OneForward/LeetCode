# leet777

from typing import List


class Solution:
    def canTransform(self, s1: str, s2: str) -> bool:
        n = len(s1)
        L1 = [i for i in range(n) if s1[i] == 'L']
        L2 = [i for i in range(n) if s2[i] == 'L']
        R1 = [i for i in range(n) if s1[i] == 'R']
        R2 = [i for i in range(n) if s2[i] == 'R']
        
        return (s1.replace('X', '')  == s2.replace('X', '') and 
                all(i1 >= i2 for i1, i2 in zip(L1, L2)) and 
                all(i1 <= i2 for i1, i2 in zip(R1, R2)))


print(Solution().canTransform(s1 = "RXXLRXRXL", s2 = "XRLXXRRLX"))
print(Solution().canTransform(s1 = "X", s2 = "L"))
print(Solution().canTransform("XXXXXLXXXLXXXX", "XXLXXXXXXXXLXX"))
print(Solution().canTransform("XXRXXLXXXX", "XXXXRXXLXX"))


