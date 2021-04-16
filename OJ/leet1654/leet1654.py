# leet1654

from typing import List

# Wrong Answer
class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        D = {0: 0}
        forbidden = set(forbidden)
        cnt = b // a + 1
        b2 = cnt * a - b
        def f(x):
            if x in D:  return D[x]
            if x < 0 or x in forbidden:  return -1
            f1 = f(x-a)
            f2 = -1
            if x+b not in forbidden:
                f2 = f(x - b2)
            ret = -1
            if f1 >= 0 and f2 >= 0: ret = min(f1+1, f2 + cnt + 1)
            elif f1 >= 0: ret = f1 + 1
            elif f2 >= 0: ret = f2 + cnt + 1
            return ret 
        return f(x)
            

# print(Solution().minimumJumps(forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9))
# print(Solution().minimumJumps(forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11))
# print(Solution().minimumJumps(forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7))
print(Solution().minimumJumps([162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98], 29, 98, 80))


