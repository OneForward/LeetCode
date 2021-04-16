# lcci17.18

from typing import List

from collections import Counter, defaultdict
class Solution:
    def shortestSeq1(self, big: List[int], small: List[int]) -> List[int]:
        n = len(big)

        Csmall = Counter(small)
        
        Cbig = defaultdict(int)

        def isok():
            for k, v in Csmall.items():
                if Cbig[k] < v: return False
            return True

        def succ(i):
            while i < n and big[i] not in Csmall: i += 1
            return i 

        rht = lft = succ(0)

        
        while rht < n: 
            Cbig[big[rht]] += 1
            if isok(): break 
            rht = succ(rht+1)
        else:
            return []

        ans = (lft, rht)
        while rht < n:
            Cbig[big[lft]] -= 1
            lft = succ(lft+1)
            if lft >= n: return ans

            while True:
                if isok(): break
                
                rht = succ(rht+1)
                if rht >= n: return ans 
                Cbig[big[rht]] += 1
                
            if rht - lft < ans[1] - ans[0]:
                ans = (lft, rht)
        return ans

    def shortestSeq2(self, big: List[int], small: List[int]) -> List[int]:
        # 144ms
        n = len(big)

        small = set(small)
        
        Cbig = defaultdict(int)           
        n_small, n_big = len(small), 0
        def isok(): return n_small <= n_big

        def succ(i):
            while i < n and big[i] not in small: i += 1
            return i 

        rht = lft = succ(0)

        while rht < n: 
            if big[rht] not in Cbig.keys(): n_big += 1
            Cbig[big[rht]] += 1
            if isok(): break 
            rht = succ(rht+1)
        else:
            return []

        ans = (lft, rht)
        while rht < n:
            Cbig[big[lft]] -= 1
            if Cbig[big[lft]] == 0: n_big -= 1
            lft = succ(lft+1)
            if lft >= n: return ans

            while True:
                if isok(): break
                
                rht = succ(rht+1)
                if rht >= n: return ans 
                if Cbig[big[rht]] == 0: n_big += 1
                Cbig[big[rht]] += 1
                
            if rht - lft < ans[1] - ans[0]:
                ans = (lft, rht)
        return ans
    
    def shortestSeq3(self, big: List[int], small: List[int]) -> List[int]:
        # 144ms, O(N), 包含关系是 multiset 的包含
        small = Counter(small)
        lft, n, n_small = 0, 0, len(small)
        
        ans = ()
        for rht, x in enumerate(big):
            if x not in small: continue

            small[x] -= 1 
            if small[x] == 0: n += 1

            while big[lft] not in small or small[big[lft]] < 0: # 移动左指针： 当其指向的字符 不会影响包含关系时
                if big[lft] in small: small[big[lft]] += 1
                lft += 1
            
            if n == n_small:
                if not ans or ans[1] - ans[0] > rht - lft: ans = (lft, rht)
        return ans 
    def shortestSeq(self, big: List[int], small: List[int]) -> List[int]:
        # 140ms, O(N), 包含关系是 set 的包含
        # sliding window
        small = Counter(set(set(small)))
        lft, n, n_small = 0, 0, len(small)
        
        ans = ()
        for rht, x in enumerate(big):
            if x not in small: continue

            small[x] -= 1 
            if small[x] == 0: n += 1

            while big[lft] not in small or small[big[lft]] < 0: # 移动左指针： 当其指向的字符 不会影响包含关系时
                if big[lft] in small: small[big[lft]] += 1
                lft += 1
            
            if n == n_small:
                if not ans or ans[1] - ans[0] > rht - lft: ans = (lft, rht)
        return ans 

            


            




        
        



        





print(Solution().shortestSeq(big = [7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7], small = [1,5,9]))
print(Solution().shortestSeq(big = [1,2,3], small = [4]))


