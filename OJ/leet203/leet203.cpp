/*
leet203


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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0); dummy.next = head;
        auto p = &dummy;
        while (p->next) {
            auto pnext = p->next;
            if (pnext->val == val) {
                p->next = pnext->next;
                delete pnext;
            }
            else p = p->next;
        }
        return dummy.next;
    }
};


int main(int argc, char const *argv[])
{

    Solution sol;   
    cout << sol.removeElements( from( {6, 1,2,6,3,4,5,6} ), 6 );
    cout << sol.removeElements( from( {6, 6} ), 6 );
    return 0;
}
