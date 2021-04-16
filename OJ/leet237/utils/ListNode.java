package utils;

public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }


    public ListNode from(int[] A) {
        ListNode dummy = new ListNode(0);
        ListNode p = dummy;
        for (int x: A) {
            p.next = new ListNode(x);
            p = p.next;
        }
        return dummy.next;
    }
}