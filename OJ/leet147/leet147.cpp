/*
leet147


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
    if (vs.empty()) return nullptr;
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

    ListNode* insertionSortList(ListNode* head) {        
        ListNode dummy;
        auto curr = head;
        while (curr) {
            auto p = &dummy;
            while (p->next && p->next->val < curr->val) {
                p = p->next;
            }
            auto cnext = curr->next;
            curr->next = p->next;
            p->next = curr;
            curr = cnext;
        }   
        return dummy.next;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.insertionSortList( from( {4,2,1,3} ) );
    cout << sol.insertionSortList( from( {-1, 5, 3, 4, 0} ) );
    cout << sol.insertionSortList( from( {} ) );
    return 0;
}
