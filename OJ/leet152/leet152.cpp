/*
leet152


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int maxProduct(const vector<int>& A) {
        int ans = INT_MIN, pos = 1, neg = 1;
        for (auto&& x: A) {
            auto oldpos = pos, oldneg = neg;
            pos = max({x, oldpos * x, oldneg * x});
            neg = max({x, oldpos * x, oldneg * x});
            ans = max(ans, pos);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxProduct({2,3,-2,4}) << endl;
    cout << sol.maxProduct({-2,0,-1}) << endl;
    return 0;
}
