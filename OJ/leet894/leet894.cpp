/*
leet894


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

class Solution {
public:

    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        
        vector<vector<TreeNode*>> v(n+1);
        v[1] = { new TreeNode{} };

        function<vector<TreeNode*>(int)> f = [&](int n) -> vector<TreeNode*> {

            if (v[n].size()) return v[n];

            auto ans = vector<TreeNode*>{};
            for (int x = 1; x < n; x += 2)
            {
                auto&& L = f(x);
                auto&& R = f(n - x - 1);
                for (auto&& lft: L) {
                    for (auto&& rht: R) {
                        ans.push_back({new TreeNode{{}, lft, rht}});
                    }
                }
            };
            return ans;
        };
        
        return f(n);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.allPossibleFBT(1) << endl;
    cout << sol.allPossibleFBT(3) << endl;
    cout << sol.allPossibleFBT(5) << endl;
    cout << sol.allPossibleFBT(7) << endl;
    return 0;
}
