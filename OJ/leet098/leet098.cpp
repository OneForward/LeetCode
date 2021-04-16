/*
leet098


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

const int null = -1;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* from(const vector<int>& v, int start = 0) {
    if (start >= v.size() || v[start] == null) return nullptr;

    TreeNode* root = new TreeNode(v[start]);
    root->left = from(v, start*2+1);
    root->right = from(v, start*2+2);
    return root;
}




class Solution {
public:
    TreeNode* root;
    vector<int> v;
    void midOrder(TreeNode* root) {
        if (root == nullptr) return;
        midOrder(root->left);
        v.push_back(root->val);
        midOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        // 16ms
        midOrder(root);
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] <= v[i-1]) return false;
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    
    // vector v = { 10,5,15,null,null,6,20 };
    vector v = { 1,1 };
    // vector v = { 2,1,3 };
    TreeNode* tree = from(v);

    Solution sol;   
    cout << boolalpha << sol.isValidBST(tree) << endl; 

    return 0;
}
