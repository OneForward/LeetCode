# leet1414
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]


class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        A = [701408733, 433494437, 267914296, 165580141, 102334155, 63245986, 39088169, 24157817, 14930352, 9227465, 5702887, 3524578, 2178309, 1346269, 832040, 514229, 317811, 196418, 121393, 75025, 46368, 28657, 17711, 10946, 6765, 4181, 2584, 1597, 987, 610, 377, 233, 144, 89, 55, 34, 21, 13, 8, 5, 3, 2, 1, 1]
        ans = 1
        def f(y, i):
            nonlocal ans
            # print(ans, y, i)
            for j in range(i, len(A)):
                if y == A[j]: return True
                if y < A[j]: continue
                if f(y - A[j], j+1): ans += 1; return True
            return False
        f(k, 0)
        return ans

# pprint(Solution().findMinFibonacciNumbers(1))
# pprint(Solution().findMinFibonacciNumbers(19))
pprint(Solution().findMinFibonacciNumbers(10))
# pprint(Solution().findMinFibonacciNumbers(7))
# pprint(Solution().findMinFibonacciNumbers(10))
# pprint(Solution().findMinFibonacciNumbers(44))


