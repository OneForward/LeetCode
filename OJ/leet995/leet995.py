# leet995

from typing import List


class Solution(object):
    def minKBitFlips(self, A, K):
        N = len(A)
        hint = [0] * N
        ans = flip = 0

        # 当我们翻转子数组形如 A[i], A[i+1], ..., A[i+K-1]
        # 我们可以在此位置置反翻转状态，并且在位置 i+K 设置一个提醒，告诉我们在那里也要置反翻转状态
        for i, x in enumerate(A):
            flip ^= hint[i]
            if x ^ flip == 0:  # 我们是否必须翻转从此开始的子数组
                ans += 1  # 翻转子数组 A[i] 至 A[i+K-1]
                if i+K > N: return -1  # 如果没办法翻转整个子数组了，那么就不可行
                flip ^= 1  
                if i+K < N: hint[i + K] ^= 1

        return ans



print(Solution().minKBitFlips(A = [0,1,0], K = 1))
print(Solution().minKBitFlips(A = [1,1,0], K = 2))
print(Solution().minKBitFlips(A = [0,0,0,1,0,1,1,0], K = 3))


