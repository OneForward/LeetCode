# leet454

from typing import List


from collections import Counter, defaultdict
class Solution:
    def fourSumCount1(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        # O(N^3) TLE
        mA = defaultdict(int, Counter(A))
        mB = defaultdict(int, Counter(B))
        mC = defaultdict(int, Counter(C))
        mD = defaultdict(int, Counter(D)) 
        
        ans = 0
        for a, ca in mA.items():
            for b, cb in mB.items():
                for c, cc in mC.items():
                    if -(a+b+c) in mD:
                        ans += ca * cb * cc * mD[-(a+b+c)]
        return ans
    
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        # O(N^2) 
        AB = Counter( a+b for a in A for b in B )
        CD = Counter( c+d for c in C for d in D )

        return sum( Nab * CD[-ab] for ab, Nab in AB.items() if -ab in CD )


print(Solution().fourSumCount(
    A = [ 1, 2],
    B = [-2,-1],
    C = [-1, 2],
    D = [ 0, 2],
))


