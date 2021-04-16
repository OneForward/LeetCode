/*
leet234


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


class Solution {
public:
    ListNode* rev(ListNode* head) {
        ListNode* prev = nullptr, *p = head, *pnext;
        while (p) {
            pnext = p->next;
            p->next = prev;
            prev = p; p = pnext;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        ListNode dummy; dummy.next = head;
        auto fast = &dummy, slow = &dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto mid = slow;
        if (fast) slow = slow->next, mid->next = nullptr;

        auto lft = head, rht = rev(slow), rht_most = rht;
        while (lft && rht) {
            if (lft->val != rht->val)  return false;
            lft = lft->next; rht = rht->next;
        }
        if (lft || rht) return false;

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha << sol.isPalindrome( from( {} ) ) << endl;
    // cout << sol.rev( from( {1,2,2,1} ) )<< endl;
    return 0;
}
