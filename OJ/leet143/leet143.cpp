/*
leet143


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

ListNode* from(vector<int>&& v, int pos = -1) {
    ListNode* head {new ListNode(0)};
    ListNode* p = head, *curr = nullptr;
    for (int i = 0; i < v.size(); ++i) {
        p->next = new ListNode(v[i]);
        p = p->next; 
        if (i == pos) curr = p;
    }
    p->next = curr;
    return head->next;
}

void disp(ListNode* p, int pos = -1) {
    int cnt = 0; ListNode* curr = nullptr;
    while (p)
    {
        printf("%d -> ", p->val); p = p->next;
        if (p && p == curr) { printf("cycle\n"); break;}
        if (cnt == pos) curr = p; cnt++;
    }
    printf("nullptr\n");
}




class Solution1 {
public:
    vector<ListNode*> v;
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        
        ListNode* p = head;
        while (p) {
            v.push_back(p); p = p->next;
        }
        int n = v.size();
        for (int i = 0; i < n/2; ++i) {
            v[i]->next = v[n-i-1];
            v[n-i-1]->next = v[i+1];
        }
        v[n/2]->next = nullptr;
    }
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // 快慢指针，后半部分倒序，前后合并
        if (head == nullptr) return;
        auto fast = head, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        auto snext = slow->next, mid = slow;
        while (snext) {
            auto tmp = snext->next;
            snext->next = slow;
            slow = snext;
            snext = tmp;
        }

        mid->next = nullptr;
        if (head == slow) return;
        
        auto pfront = head, pback = slow;
        while (true) {
            auto tmp1 = pfront->next;
            auto tmp2 = pback->next;
            pfront->next = pback;
            if (tmp1 == pback || tmp1 == pback->next ) break;
            pback->next = tmp1;
            pfront = tmp1; pback = tmp2;
        }
    }
};

int main(int argc, char const *argv[])
{   
    ListNode* l1 = from( {0, } ); disp(l1);

    Solution sol;   
    sol.reorderList(l1); 
    disp(l1);

    return 0;
}
