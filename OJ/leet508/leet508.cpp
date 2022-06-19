/*
leet508


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> M;
        function<int(TreeNode*)> f = [&](TreeNode* root) {
            int x = root->val;
            if (root->left) x += f(root->left);
            if (root->right) x += f(root->right);
            M[x]++;
            return x;
        };

        f(root);
        int cnt = INT_MIN;
        for (auto&& [k, v]: M)  cnt = max(cnt, v);

        vector<int> ans;
        for (auto&& [k, v]: M)  if (v == cnt) ans.push_back(k);
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findFrequentTreeSum( toTree( {5, 2, -5} ) ) << endl;
    return 0;
}
