# leet638

from typing import List


class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        M = len(needs)
        D = {(0,) * M: 0}
        
        def f(w):
            if tuple(w) in D: return D[tuple(w)]

            v = sum( pi * wi for pi, wi in zip(price, w) )
            for s in special:
                for i in range(M): 
                    if w[i] < s[i]: break
                else:
                    for i in range(M): w[i] -= s[i]
                    v = min(v, f(w) + s[-1] )
                    for i in range(M): w[i] += s[i]

            D[tuple(w)] = v
            return v 
        return f(needs)




print(Solution().shoppingOffers([2,5], [[3,0,5],[1,2,10]], [3,2]))
print(Solution().shoppingOffers([2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]))


