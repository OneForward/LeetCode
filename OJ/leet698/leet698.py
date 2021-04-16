from typing import List

cnt = 0
def gen(L, target):
    def _gen(L, target):
        global cnt
        cnt = cnt + 1
        if not L or target < 0: return []
        if target == 0: return [[]]
        ans = []
        if len(L) > 1 and L[0] + L[-1] <= target:
            for Si in _gen(L[1:], target-L[0]):
                ans.append( [L[0]] + Si )
        return ans + _gen(L[1:], target)
    L = sorted(L, reverse=True)
    return _gen(L, target)


# def check(S: set, L: List[int], ans: List[List]):
#     for si in S: pass
        

# def f(L: List[int], target):
#     S = set(gen(L, target))
#     for si in S:
#         L2 = L.copy()
#         for x in si: L2.remove(x)
#         check(S, L2)


# class Solution:
#     def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
#         if k == 1: return True
#         if sum(nums) % k: return False
#         target = sum(nums) / k 
#         nums.sort(reverse=True)

#         return f(nums, target)

# print(Solution().canPartitionKSubsets( [4, 3, 2, 3, 5, 2, 1] , 4 ))

# print(_gen([4, 3, 2, 3, 5, 2, 1], 5))
print(gen([4, 3, 2, 3, 5, 2, 1, 1, 1, 1, 1, 1], 5))
print(f"cnt = {cnt}")
