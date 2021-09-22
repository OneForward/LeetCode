/*
leet725


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int K) {
        vector<ListNode*> ans;
        int len = 0; auto p = head;
        while (p) len++, p = p->next;
        int more = len % K, normal = K - more, per = len / K;
        
        auto cutoff = [](ListNode* p, int len) {
            while (--len > 0 and p) p = p->next;
            auto pnext = p;
            if (p) { pnext = p->next; p->next = nullptr; }
            return pnext;
        };
        
        p = head;
        ans.push_back(p);
        while (--K) {
            p = cutoff(p, per+( K >= normal ? 1 : 0 ));
            ans.push_back(p);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.splitListToParts( toList({1,2,3}), 5 ) << endl;
    cout << sol.splitListToParts( toList({1,2,3,4,5,6,7,8,9,10}), 3 ) << endl;
    return 0;
}
