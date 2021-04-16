/*
leet092


*/


#include <iostream>
#include <vector>
#include <queue>
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 4ms
        ListNode newhead = ListNode(); newhead.next = head;
        ListNode* lft = &newhead, *prev, *curr, *next;  n -= m;
        while (--m) lft = lft->next; prev = lft->next; curr = prev->next; 

        while (n--) {
            next = curr->next; curr->next = prev; prev = curr; curr = next;
        }
        lft->next->next = curr; lft->next = prev; 
        return newhead.next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* l1 = from( {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ); disp(l1);

    Solution sol;
    auto ans = sol.reverseBetween(l1, 2, 7); disp(ans);
    return 0;
}
