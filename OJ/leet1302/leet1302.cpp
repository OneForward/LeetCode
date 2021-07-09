/*
leet1302


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> Q;
        if (root) Q.push(root);
        while (Q.size()) {
            int len = Q.size(); ans = 0;
            while (len--) {
                auto p = Q.front(); Q.pop();
                ans += p->val;
                if (p->left) Q.push(p->left);
                if (p->right) Q.push(p->right);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.deepestLeavesSum( toTree({1,2,3,4,5,null,6,7,null,null,null,null,8}) ) << endl;
    cout << sol.deepestLeavesSum( toTree({6,7,8,2,7,1,3,9,null,1,4,null,null,null,5}) ) << endl;
    return 0;
}
