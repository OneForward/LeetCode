/*
lcof22


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto Head = ListNode{0, head};
        auto p = &Head, q = &Head;
        while (k--) p = p->next;
        while (p) p = p->next, q = q->next;
        return q;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.getKthFromEnd( toList({1,2,3,4,5,6,7}), 2 ) << endl;
    return 0;
}
