# leet1622

from typing import List


def fastInv(a, m):
    # 求 a^(-1) MOD m 
    # 对于 m 是质数，恰有 a^(m-1) = 1 MOD m 
    # 因此求 a^(m-2) MOD M 即可
    n = m - 2 
    ans = 1
    while n:
        if n % 2: ans = ans * a  % m
        a *= a; a %= m
        n //= 2 
    return ans 

M = 1000000007
class Fancy:

    def __init__(self):
        self.A = [1]
        self.B = [0] 
        self.L = []


    def append(self, val: int) -> None:
        self.L.append(val)
        a, b = self.A[-1], self.B[-1]
        self.A.append(a)
        self.B.append(b)

    def addAll(self, inc: int) -> None:
        self.B[-1] += inc

    def multAll(self, m: int) -> None:
        self.A[-1] *= m % M
        self.B[-1] *= m % M

    def getIndex(self, i: int) -> int:
        if i >= len(self.L): return -1
        ai, bi, a, b = self.A[i], self.B[i], self.A[-1], self.B[-1]
        aii = fastInv(ai, M)
        return (aii * a * self.L[i] + b - aii * a * bi) % M

fancy = Fancy()
print(fancy.append(2));   # 奇妙序列：[2]
print(fancy.addAll(3));   # 奇妙序列：[2+3] -> [5]
print(fancy.append(7));   # 奇妙序列：[5, 7]
print(fancy.multAll(2));  # 奇妙序列：[5*2, 7*2] -> [10, 14]
print(fancy.getIndex(0)); # 返回 10
print(fancy.addAll(3));   # 奇妙序列：[10+3, 14+3] -> [13, 17]
print(fancy.append(10));  # 奇妙序列：[13, 17, 10]
print(fancy.multAll(2));  # 奇妙序列：[13*2, 17*2, 10*2] -> [26, 34, 20]
print(fancy.getIndex(0)); # 返回 26
print(fancy.getIndex(1)); # 返回 34
print(fancy.getIndex(2)); # 返回 20 
