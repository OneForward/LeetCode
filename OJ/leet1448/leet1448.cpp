/*
leet1448


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:

    int goodNodes(TreeNode* root) {
        int cnt = 0;
        function<void(TreeNode*, int)> f = [&](TreeNode* root, int M) {
            if (not root) return;
            if (M <= root->val) cnt++;
            M = max(M, root->val);
            f(root->left, M);
            f(root->right, M);
        };
        f(root, INT_MIN);
        return cnt;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.goodNodes( toTree({3,1,4,3,null,1,5})) << endl;
    cout << sol.goodNodes( toTree({3,3,null,4,2})) << endl;
    cout << sol.goodNodes( toTree({1})) << endl;
    return 0;
}
