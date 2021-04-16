# leet402

from typing import List

class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        # 单调栈 O(N)
        numStack = []
        
        # Construct a monotone increasing sequence of digits
        for digit in num:
            while k and numStack and numStack[-1] > digit:
                numStack.pop()
                k -= 1
        
            numStack.append(digit)
        
        # - Trunk the remaining K digits at the end
        # - in the case k==0: return the entire list
        finalStack = numStack[:-k] if k else numStack
        
        # trip the leading zeros
        return "".join(finalStack).lstrip('0') or "0"



print(Solution().removeKdigits(num = "1432219", k = 3))


