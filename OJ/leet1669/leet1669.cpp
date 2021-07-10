/*
leet1669


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto Head = ListNode{{}, list1};
        auto p = &Head;
        for (int i = 0; i < a; i++)
        {
            p = p->next;
        }
        
        auto q = p->next;

        for (int i = a; i <= b; i++)
        {
            q = q->next;
        }
        


        p->next = list2;
        while (p->next) p = p->next;
        p->next = q;

        return Head.next;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.mergeInBetween(toList({0,1,2,3,4,5}),  3,  4,  toList({1000000,1000001,1000002})) << endl;
    cout << sol.mergeInBetween(toList({0,1,2,3,4,5,6}),  2,  5,  toList({1000000,1000001,1000002,1000003,1000004})) << endl;
    return 0;
}
