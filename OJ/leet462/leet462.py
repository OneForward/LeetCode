# leet462

from typing import List


class Solution1:
    def minMoves2(self, A: List[int]) -> int:
        # n log n
        median = sorted(A) [len(A) // 2]
        return sum(abs(x-median) for x in A)



def median_nlogn(A:List[int]) -> int :
    return sorted(A)[len(A)//2]


def partition(A:List[int], lo: int, hi: int) -> int :
    pivotIndex = random.randint(lo, hi)
    A[pivotIndex], A[hi] = A[hi], A[pivotIndex]
    pivot = A[hi]
    i = lo
    for j in range(lo, hi+1):
        if A[j] < pivot:
            A[i], A[j] = A[j], A[i]
            i += 1 
    A[i], A[hi] = A[hi], A[i]
    return i 


def quick_select(A:List[int], lo: int, hi: int, k: int) -> int :
    # O(N) on average, O(N^2) in worst case
    p = partition(A, lo, hi)
    if p-lo == k:
        return A[p]
    elif p-lo > k:
        return quick_select(A, lo, p-1, k)
    else:
        return quick_select(A, p+1, hi, k-p+lo-1)

def meadian_on(A):
    return quick_select(A, 0, len(A)-1, len(A)//2)

def median_of_medians(A, k):

    #divide A into sublists of len 5
    sublists = [A[j:j+5] for j in range(0, len(A), 5)]
    medians = [sorted(sublist)[len(sublist)//2] for sublist in sublists]
    if len(medians) <= 5:
        pivot = sorted(medians)[len(medians)//2]
    else:
        #the pivot is the median of the medians
        pivot = median_of_medians(medians, len(medians)//2)

    #partitioning step
    low = [j for j in A if j < pivot]
    high = [j for j in A if j > pivot]

    if k < len(low):
        return median_of_medians(low,k)
    elif k < len(A)-len(high):
        return pivot
    else: #pivot = k
        return median_of_medians(high,k-len(A)+len(high))

class Solution:

    def minMoves2(self, A: List[int]) -> int:
        # O(N) median of median algorithm
        median = quick_select(A, 0, len(A)-1, len(A)//2)
        # median = median_of_medians(A,  len(A)//2)
        return sum(abs(x-median) for x in A)




# print(Solution().minMoves2([1,2,3]))


import random 

# A = random.choices(range(100), k=25)
A=[69, 63, 42, 1, 41, 12, 72, 45, 65, 95, 59, 48, 62, 84, 46, 69, 33, 58, 93, 75, 86, 23, 80, 0, 72]
A = [1,1,1,1,3,2,2,2,2]
A = [1,2,5,8,0]

print(A)
# print(median_nlogn(A))
# print(median_of_medians(A, len(A)//2))
print(meadian_on(A))
