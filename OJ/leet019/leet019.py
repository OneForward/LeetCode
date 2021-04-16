# from typing import List
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    def print(self): 
        next = self
        while next:
            print(f'{next.val} -> ', end='')
            next = next.next
        print(None)

class Solution:
    def removeNthFromEnd1(self, head: ListNode, n: int) -> ListNode:
        # 56ms
        L = []
        next = head
        while next:
            L.append(next)
            next = next.next
        if len(L) == n:
            head = head.next
        else:
            L[-n-1].next = L[-n].next
        return head

    def removeNthFromEnd2(self, head: ListNode, n: int) -> ListNode:
        # 36ms
        N = 0
        next = head
        while next:
            N += 1
            next = next.next
        if N == n:
            head = head.next
        else:
            next = head
            while N > n+1:
                N -= 1
                next = next.next
            next.next = next.next.next
        return head

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # 32ms
        cnt = -1
        p1, p2 = None, head
        while p2:
            cnt += 1
            p2 = p2.next
            if cnt == n: 
                p1 = head
                break
        
        while p2:
            p1 = p1.next
            p2 = p2.next
        if p1 is None:
            head = head.next
        else:
            p1.next = p1.next.next
        return head

    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        return head
p = head = ListNode(0)
head.print()
m, n = 1, 1
print(Solution().reverseBetween(head, m, n))

p = head = ListNode(0)
for i in range(1, 2):
    p.next = ListNode(i)
    p = p.next

head.print()
m, n = 1, 1
Solution().reverseBetween(head, m, n).print()

p = head = ListNode(0)
for i in range(1, 10):
    p.next = ListNode(i)
    p = p.next

head.print()
m, n = 1, 10
Solution().reverseBetween(head, m, n).print()