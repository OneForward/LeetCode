/*
leet024


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
    ListNode* swapPairs(ListNode* head) {
        // 4ms
        ListNode prev_head, *p1 = &prev_head, *p2, *p1_next; prev_head.next = head;
        while (p1->next) {
            p2 = p1->next->next;
            if (!p2) break;

            p1->next->next = p2->next; p2->next = p1->next; 
            p1->next = p2; p1 = p2->next;
        }
        return prev_head.next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* l1 = from( {1, 2, 3, 4, 5, 6} ); disp(l1);

    Solution sol;
    auto ans = sol.swapPairs(l1); disp(ans);
    return 0;
}
