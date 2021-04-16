# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from itertools import chain
from typing import List
class Solution:
    def mergeKLists(self, lists: List[List]) -> List:
        return sorted(chain(*lists))

print(Solution().mergeKLists( [[1, 4, 5], [1, 3, 4], [2, 6] ]  ))