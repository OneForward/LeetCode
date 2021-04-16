/*
leet082


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
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
    ListNode* deleteDuplicates(ListNode* head) {
        // unsafe , memory leak, 12ms
        if (head == nullptr || head->next == nullptr) return head;
        ListNode new_head = ListNode(); new_head.next = head;
        ListNode* lft = &new_head, *rht = head; int cnt = 0, prev_rht_val = rht->val;
        while (rht->next) {
            cnt++; prev_rht_val = rht->val;
            if (rht->val != rht->next->val) {
                if (cnt == 1) lft->next->val = rht->val, lft = lft->next;
                cnt = 0;
            }
            rht = rht->next; 
        }
        if (prev_rht_val != rht->val) lft->next->val = rht->val, lft = lft->next;
        lft->next = nullptr;
        return new_head.next;
    }
};

int main(int argc, char const *argv[])
{
    // ListNode* l1 = from( {1, 1, 2, 3, 3, 4, 4, 4, 5, 6} ); disp(l1);
    ListNode* l1 = from( {1, 1,2} ); disp(l1);

    Solution sol;
    auto ans = sol.deleteDuplicates(l1); disp(ans);
    return 0;
}
