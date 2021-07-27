/*
leet671


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int f(TreeNode* root, int x) {
        if (not root) return -1;
        if (root->val != x) return root->val;
        auto flft = f(root->left, x);
        auto frht = f(root->right, x);
        return (flft == -1 or frht == -1) ? max(flft, frht) : min(flft, frht);
    }
    int findSecondMinimumValue(TreeNode* root) {
        return f(root, root->val);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findSecondMinimumValue(toTree({2,2,5,null,null,5,7})) << endl;
    cout << sol.findSecondMinimumValue(toTree({1,1,3,1,1,3,4,3,1,1,8})) << endl;
    cout << sol.findSecondMinimumValue(toTree({2,2,2})) << endl;
    return 0;
}
