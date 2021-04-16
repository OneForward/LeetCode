/*
leet025


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <utility>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x=0) : val(x), next(nullptr) {}
};

ListNode* from(vector<int>&& v) {
    ListNode* head {new ListNode(0)};
    ListNode* p = head;
    for (auto vi: v) {
        p->next = new ListNode(vi);
        p = p->next;
    }
    return head->next;
}

void disp(ListNode* p) {
    while (p)
    {
        printf("%d -> ", p->val); p = p->next;
    }
    printf("nullptr\n");
}

class Solution {
public:
    void swap(ListNode*& a, ListNode*& b) {
        ListNode* bnext = b->next;
        b->next = a; a = b; b = bnext;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 32ms
        ListNode prev_head; prev_head.next = head;
        
        ListNode *p1 = &prev_head, *p2;

        while (p1) {
            p2 = p1;
            for (int i=0; i<k; ++i) {
                p2 = p2->next; if (p2 == nullptr) goto ret;
            }

            ListNode* a = p1->next, *b = a->next, *p1next = p1->next, *p2next = p2->next;
            while (a != p2) {
                swap(a, b);
            }

            p1next->next = p2next; p1->next = p2; p1 = p1next;

        }
        ret:
            return prev_head.next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* l1 = from( {1, 2, 3, 4, 5, 6, 7,  } ); disp(l1);
    Solution sol;
    auto ans = sol.reverseKGroup(l1, 2); disp(ans);

    return 0;
}
