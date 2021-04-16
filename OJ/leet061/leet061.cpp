/*
leet061


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
    ListNode* rotateRight(ListNode* head, int k) {
        // 8ms
        if (head == nullptr) return head;

        ListNode* p = head; int cnt = 0;
        while (p && p->next) p = p->next, cnt++;
        p->next = head;

        k = cnt + 1 - k % (cnt + 1);
        while (k--) p = p->next; head = p->next;
        p->next = nullptr;

        return head;
    }
};

int main(int argc, char const *argv[])
{
    
    
    
    Solution sol;
    for (int k = 0; k < 15; ++k) {
        // ListNode* l1 = from( {1, 2, 3, 4, 5} );  cout << "k = " << k << ": ";
        ListNode* l1 = from( {0, 1, 2} );  cout << "k = " << k << ": ";
        auto ans = sol.rotateRight(l1, k); disp(ans);
    }
    
    return 0;
}
