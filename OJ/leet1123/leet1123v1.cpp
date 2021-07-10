/*
leet1123


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int depth(TreeNode* root) {
        return root ? max(depth(root->left), depth(root->right)) + 1 : 0;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (not root) return {};

        int H = depth(root);

        vector<TreeNode*> u,  v;
        function<void(TreeNode*, int)> f = [&](TreeNode* root, int h) {
            if (not root) return;
            v.push_back(root);

            if (h == H) {
                if (u.empty()) u = v;
                size_t i = 0, len = min(u.size(), v.size());
                for ( ; i < len and u[i] == v[i]; i++);
                while (u.size() > i) u.pop_back();
            }
            if (root->left) f(root->left, h + 1);
            if (root->right) f(root->right, h + 1);
            v.pop_back();
        };

        f(root, 1);
        return u.back();
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.lcaDeepestLeaves( toTree({})) << endl;
    cout << sol.lcaDeepestLeaves( toTree({3,5,1,6,2,0,8,null,null,7,4})) << endl;
    cout << sol.lcaDeepestLeaves( toTree({1})) << endl;
    cout << sol.lcaDeepestLeaves( toTree({0,1,3,null,2})) << endl;
    return 0;
}
