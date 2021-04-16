/*
leet083


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
        // unsafe , memory leak, 16ms
        if (head == nullptr) return head;
        ListNode new_head = ListNode(); new_head.next = head;
        ListNode* lft = head, *rht = head;
        while (rht && rht->next) {
            if (rht->val != rht->next->val) lft->next->val=rht->next->val, lft = lft->next;
            rht = rht->next;
        }
        lft->next = nullptr;
        return new_head.next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* l1 = from( {1, 1, 2, 3, 3, 4, 4, 4, 5, 6} ); disp(l1);

    Solution sol;
    auto ans = sol.deleteDuplicates(l1); disp(ans);
    return 0;
}
