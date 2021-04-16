# leet004

from typing import List


class Solution:
    def findMedianSortedArrays(self, A: List[int], B: List[int]) -> float:
        if len(A) > len(B): return self.findMedianSortedArrays(B, A)
        if len(A) == 0: 
            if len(B) % 2 == 0: return (B[len(B)//2] + B[len(B)//2-1]) / 2
            else: return B[len(B) // 2]

        half = (len(A) + len(B)) // 2
        lft, rht = 0, len(A)+1
        Alft, Blft = 0, 0
        while lft < rht:
            Alft = (lft + rht) // 2
            Blft = half - Alft
            # print(f'Alft = {Alft}, Blft = {Blft}, lft = {lft}, rht = {rht}')
            if Alft == 0:
                if A[Alft] < B[Blft-1]: lft = Alft + 1
                else: break
            elif Alft == len(A):
                if A[Alft-1] > B[Blft]: rht = Alft
                else: break 
            else:
                if A[Alft] < B[Blft-1]: lft = Alft + 1
                elif A[Alft-1] > B[Blft]: rht = Alft
                else: break
        if (len(A) + len(B)) % 2 == 0:
            if Alft == 0:
                mlft = B[Blft-1]
                mrht = A[0] if Blft == len(B) else min(A[0], B[Blft])
            elif Alft == len(A):
                mlft = A[Alft-1] if Blft == 0 else max(A[Alft-1], B[Blft-1])
                mrht = B[Blft]
            else:
                mlft = max(A[Alft-1], B[Blft-1])
                mrht = min(A[Alft], B[Blft])
            return (mlft + mrht) / 2
        else:
            if Alft == len(A): return B[Blft]
            else: return min(A[Alft], B[Blft])


# print(Solution().findMedianSortedArrays([1,2], [-1, 3]))
# print(Solution().findMedianSortedArrays([], [2, 3]))
print(Solution().findMedianSortedArrays([1], [2, 3]))
print(Solution().findMedianSortedArrays([], [2]))
print(Solution().findMedianSortedArrays([2], [2]))
print(Solution().findMedianSortedArrays([1,3], [2]))
print(Solution().findMedianSortedArrays([1,2], [3,4]))


