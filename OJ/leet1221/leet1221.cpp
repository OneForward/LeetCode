/*
leet1221


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0, ans = 0;
        for (auto&& ch: s) {
            if (ch == 'L') cnt++;
            else cnt--;
            if (cnt == 0) ans++;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.balancedStringSplit("RLRRLLRLRL") << endl;
    cout << sol.balancedStringSplit("RLLLLRRRLR") << endl;
    cout << sol.balancedStringSplit("LLLLRRRR") << endl;
    return 0;
}
