#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(); ListNode* p3 = l3;
        while (l1 && l2) {
            if (l1->val < l2->val) p3->next = new ListNode(l1->val), l1 = l1->next;
            else p3->next = new ListNode(l2->val), l2 = l2->next;
            p3 = p3->next;
        }
        while (l1) {
            p3->next = new ListNode(l1->val), l1 = l1->next; p3 = p3->next;
        }
        while (l2) {
            p3->next = new ListNode(l2->val), l2 = l2->next; p3 = p3->next;
        }
        return l3->next;
    }
};

