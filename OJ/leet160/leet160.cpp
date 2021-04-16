/*
leet160


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

class Solution {
public:
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        // 84ms, 哈希法, O(N) Space, O(M+N) Time
        unordered_set< ListNode*> S;
         ListNode* p = headA;
        while (p) {
            S.insert(p); p = p->next;
        }
        p = headB;
        while (p) {
            if (S.find(p) != S.end()) return p;
            p = p->next;
        }
        return nullptr;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 48ms, 双链表法, O(1) Space, O(M+N) Time
         ListNode* pA = headA, *pB = headB;
        while (pA != pB) {
            if (pA == nullptr) pA = headB;
            else pA = pA->next;
            if (pB == nullptr) pB = headA;
            else pB = pB->next;
        }  
        return pA;
    }
};


int main(int argc, char const *argv[])
{
    ListNode* l1 = from( {1, 2, 3, 4, 5, 6}); disp(l1);


    return 0;
}
