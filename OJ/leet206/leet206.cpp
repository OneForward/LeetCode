/*
leet206


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x=0) : val(x), next(nullptr) {}
    ListNode(const vector<int>& vs, int pos = -1) {
        vector<int> v = vs;
        ListNode head;
        ListNode* p = &head, *curr = nullptr;
        for (int i = 0; i < v.size(); ++i) {
            p->next = new ListNode(v[i]);
            p = p->next; 
            if (i == pos) curr = p;
        }
        p->next = curr;
        *this = *head.next;
    }
};

ListNode* from(const vector<int>& vs, int pos = -1) {
    return new ListNode(vs, pos);
}

ostream& operator<<(ostream& os, ListNode* p) {
    while (p)
    {
        os << p->val << " -> "; p = p->next;
    }
    os << "nullptr" << endl;
    return os;
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *curr = head, *next;
        while (curr) {
            next = curr->next; curr->next = prev;
            prev = curr; curr = next;
        }
        return prev;
    }
};


int main(int argc, char const *argv[])
{
    ListNode* L1 = from( {1, 2, 3, 4, 5, 6} ); disp(L1);
    Solution sol;   cout << sol.reverseList(L1);

    return 0;
}
