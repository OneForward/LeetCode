# leet464


from typing import Set

class Solution:
    def canIWin1(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        # TLE
        if desiredTotal == 0: return True
        def f(A: Set[int], target: int) -> bool:
            if target <= 0: return False
            Acopy = A.copy()

            for x in A:
                Acopy.remove(x)
                if not f(Acopy, target-x): return True
                Acopy.add(x)
            return False
        
        return f(set(range(1, maxChoosableInteger+1)), desiredTotal)

        
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        # 484ms
        # 递归+记忆化 => 自顶向下动态规划
        if desiredTotal == 0: return True
        if desiredTotal > maxChoosableInteger * (maxChoosableInteger + 1) // 2: return False

        M = {}
        def f(A: Set[int],  key: int, target: int) -> bool:
            if key in M: return M[key]

            if target <= 0: 
                M[key] = False
                return False

            Acopy = A.copy()
            for x in A:
                Acopy.remove(x)
                if not f(Acopy, key | (1<<x), target-x): 
                    M[key] = True
                    return True
                Acopy.add(x)
            
            M[key] = False 
            return False

        return f(set(range(1, maxChoosableInteger+1)), 0, desiredTotal)

# print(Solution().canIWin1(16, 60))
print(Solution().canIWin(16, 60))
print(Solution().canIWin(5, 10))
print(Solution().canIWin(10, 11))

