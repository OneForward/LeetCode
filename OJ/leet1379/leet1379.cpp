/*
leet1379


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans {};
        function<void(TreeNode*, TreeNode*)> f = [&](TreeNode* p1, TreeNode* p2) {
            if (not p1 or ans) return;
            if (p1 == target) { ans = p2; return; }
            f(p1->left, p2->left);
            f(p1->right, p2->right);
        };
        f(original, cloned);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
