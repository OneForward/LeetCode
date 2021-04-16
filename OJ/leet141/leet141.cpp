/*
leet141


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
    unordered_set<ListNode*> S;
    bool hasCycle(ListNode *head) {
        ListNode * p = head;
        while (p) {
            if (S.find(p) == S.end()) S.insert(p);
            else return true;
            p = p->next;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *NIL{new ListNode()}, *p = head, *pnext;
        while (p) {
            if (p == NIL) return true;
            pnext = p->next;
            p->next = NIL;
            p = pnext;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{   
    ListNode* l1 = from( {3, 2, 0, -4}, 1 ); disp(l1, 1);
    // ListNode* l1 = from( {3, 2, 0, -4}, -1 ); disp(l1, -1);

    Solution sol;   
    cout << boolalpha << sol.hasCycle(l1) << endl;

    return 0;
}
