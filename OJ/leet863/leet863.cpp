/*
leet863


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        VVI G(501);

        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root->left) {
                G[root->left->val].push_back(root->val);
                G[root->val].push_back(root->left->val);
                dfs(root->left);
            }
            if (root->right) {
                G[root->right->val].push_back(root->val);
                G[root->val].push_back(root->right->val);
                dfs(root->right);
            }
        };
        
        dfs(root);

        bool visited[501]{};
        auto start = target->val;
        // auto start = target;
        queue<int> Q; Q.push(start); visited[start] = true;
        while (Q.size() and k--) {
            int len = Q.size();
            while (len--) {
                auto u = Q.front(); Q.pop();
                for (auto&& v: G[u]) {
                    if (visited[v]) continue;
                    Q.push(v); visited[v] = true;
                }
            }
        }

        vector<int> ans;
        while (Q.size()) ans.push_back(Q.front()), Q.pop();
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.distanceK(toTree({3,5,1,6,2,0,8,null,null,7,4}), 5, 2 ) << endl;
    return 0;
}
