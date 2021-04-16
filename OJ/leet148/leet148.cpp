/*
leet148


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

ostream& operator<<(ostream& os, ListNode* p) {
    while (p)
    {
        os << p->val << " -> "; p = p->next;
    }
    os << "nullptr" << endl;
    return os;
}

class Solution {
public:
    ListNode* sortList1(ListNode* head) {
        // Time O(N log N), Space O(N)
        vector<int> v; ListNode* p = head;
        while (p) {
            v.push_back(p->val); p = p->next;
        }
        sort(v.begin(), v.end());

        p = head; 
        for (auto vi: v) {
            p->val = vi; p = p->next;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        // merge sort, Time O(N log N), Space O(1)
        int length = 0;
        auto p = head;
        while (p) length++, p = p->next;

        ListNode dummy; dummy.next = head;
        for (int len = 1; len < length; len <<= 1) {
            auto curr = dummy.next;
            auto tail = &dummy;
            while (curr) {
                auto rht = cut(curr, len);
                auto lft = curr;
                curr = cut(rht, len);
                tail->next = merge(lft, rht);
                while (tail->next) tail = tail->next;
            }
        }
        return dummy.next;
    }
    ListNode* cut(ListNode* p, int n) {
        // split at n-th node, return (n+1)-th node
        while (--n && p) p = p->next;

        if (p == nullptr) return nullptr;
        auto next_head = p->next;
        p->next = nullptr;
        return next_head;
    }

    ListNode* merge(ListNode* lft, ListNode* rht) {
        ListNode dummy;
        auto cur = &dummy;

        while (lft && rht) {
            if (lft->val < rht->val) {
                cur = cur->next = lft; lft = lft->next;
            }
            else {
                cur = cur->next = rht; rht = rht->next;
            }
        }
        if (lft) cur->next = lft;
        if (rht) cur->next = rht;
        return dummy.next;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;  
    // auto L1 = from({3,4}), L2 = from({1,});
    // cout << sol.merge( from({3,4}), from({1,}) );
    // auto L = sol.merge(L1, L2); disp(L);
    // auto L = sol.cut(L1, 1); disp(L);

    // ListNode L({1,2,3});
    // cout << &L;
    cout << sol.sortList(from({-1,5,3,4,0}));

    return 0;
}
