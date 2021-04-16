/*
leet530


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> v;

    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        v.clear();
        inorder(root);
        int ans = v[1] - v[0];
        for (int i = 2; i < v.size(); ++i) { 
            ans = max(ans, v[i] - v[i-1]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   

    return 0;
}
