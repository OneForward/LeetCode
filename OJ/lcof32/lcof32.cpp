/*
lcof32


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> Q; 
        bool flag = false;
        if (root) Q.push_back(root);
        while (Q.size()) {
            int len = Q.size();
            ans.push_back({}); flag = !flag;
            if (flag) {
                while (len--) {
                    auto x = Q.front(); Q.pop_front();
                    if (x->left) Q.push_back(x->left);
                    if (x->right) Q.push_back(x->right);
                    ans.back().push_back(x->val); 
                }
            }
            else {
                while (len--) {
                    auto x = Q.back(); Q.pop_back();
                    if (x->right) Q.push_front(x->right);
                    if (x->left) Q.push_front(x->left);
                    ans.back().push_back(x->val); 
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.levelOrder( toTree({1,2,3,4,5,6}) ) << endl;
    return 0;
}
