# leet239

from typing import List

from collections import deque

class Solution:
    def maxSlidingWindow1(self, A: List[int], k: int) -> List[int]:
        # 双端队列法
        # 本质是维护一个严格单调递减的双端队列, 同时保存顺序信息和最值信息
        Q = deque()
        for i in range(k):
            while Q and A[i] > A[Q[-1]]: Q.pop()
            Q.append(i)
        ans = [A[Q[0]]]

        for i in range(k, len(A)):
            if Q and Q[0] <= i - k: Q.popleft()
            while Q and A[i] > A[Q[-1]]: Q.pop()
            Q.append(i)
            ans.append(A[Q[0]])

        return ans 
    def maxSlidingWindow(self, A: List[int], k: int) -> List[int]:
        # 动态规划法
        # 将数组分成大小为 k 的块，
        # 在每个块内，lft[i] 是从块内左端开始的最大值
        # rht[i] 是从块内右端开始的最大值
        # ans[i] = max(rht[i], lft[i+k-1])
        
        n = len(A)
        lft, rht = A.copy(), A.copy()
        for blk in range(0, n, k):
            for i in range(blk+1, min(n, blk+k)):
                lft[i] = max(lft[i-1], A[i])
            for i in range(min(blk+k, n)-1, blk, -1):
                rht[i-1] = max(rht[i], A[i-1])
        return  [max(rht[i], lft[i+k-1]) for i in range(n-k+1)]


print(Solution().maxSlidingWindow(A = [1,3,-1,-3,5,3,6,7],  k = 3))
print(Solution().maxSlidingWindow([1,-1], 1))


