
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseList1(self, head: ListNode) -> ListNode:
        def rev(curr, prev):
            if curr is None: return prev
            nextNode, curr.next = curr.next, prev
            return rev(nextNode, curr)
        return rev(head, None)

    def reverseList(self, head: ListNode) -> ListNode:
        prev, curr = None, head
        while curr:
            nextNode, curr.next = curr.next, prev 
            prev, curr = curr, nextNode
        return prev 

def printList(node):
    while node:
        print(node.val)
        node = node.next       
            

head = ListNode(-1)
p = head 
for i in range(3):
    p.next = ListNode(i)
    p = p.next

printList(head)
rev = Solution().reverseList(head)
printList(rev)