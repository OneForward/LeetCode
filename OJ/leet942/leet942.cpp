/*
leet942


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class SolutionBad {
public:
    vector<int> diStringMatch(string s) {
        int N = s.size();

        vector<int> ans(N+1);

        int lft = 0, rht = N;
        if (s[0] == 'D') ans[0] = rht--;
        else ans[0] = lft++;

        auto prev = s.back();
        auto cnt = 1;
        for (int i = N - 1; i >= 0; i--)
        {
            if (s[i] != prev) cnt = 1, prev = s[i];
            ans[i+1] = cnt++; 
        }

        for (int i = 0; i < N; i++)
        {
            auto ch = s[i], target = (ans[i + 1] == 1 ? 'I' : 'D');
            ans[i + 1] = (ch == target ? rht-- : lft++);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int N = s.size();

        vector<int> ans; ans.reserve(N + 1);

        int lo = 0, hi = N;
        for (auto ch: s) {
            if (ch == 'I') ans.push_back( lo++ );
            else ans.push_back(hi--);
        }
        ans.push_back(lo);
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.diStringMatch("IDID") << endl;
    cout << sol.diStringMatch("III") << endl;
    cout << sol.diStringMatch("DDI") << endl;
    return 0;
}
