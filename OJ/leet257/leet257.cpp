/*
leet257


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const int null = -1;

TreeNode* from(const vector<int>& vs) {
    vector<int> v = vs;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == null && 2*i+1 < v.size()) v.insert(v.begin()+2*i+1, null);
        if (v[i] == null && 2*i+2 < v.size()) v.insert(v.begin()+2*i+2, null);
    }
    vector<TreeNode*> t(v.size());
    for (int i = v.size()-1; i >= 0; --i) {
        if (v[i] != null) {
            t[i] = new TreeNode(v[i]);
            if (2*i+1 < v.size()) t[i]->left = t[2*i+1];
            if (2*i+2 < v.size()) t[i]->right = t[2*i+2];
        }
    }
    return t[0];
}

void disp(TreeNode* root) {
    TreeNode* flag = new TreeNode();
    queue<TreeNode*> Q; Q.push(root); Q.push(flag);
    while (Q.size() > 1) {
        auto p = Q.front(); Q.pop();
        if (p == flag) Q.push(p); 
        else if (p == nullptr) cout << "null, ";
        else {
            cout << p->val << ", ";
            if (p->left == nullptr && p->right == nullptr) continue;
            Q.push(p->left);
            Q.push(p->right);
        } 
    }
    cout << endl; delete flag;
}


// overload for ostream of vectors
template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

// overload for ostream of vectors of vectors
template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}

string join(const vector<int>& path) {
    string s;
    for (auto x: path) {
        if (s.size()) s += "->";
        s += to_string(x);
    }
    return s;
}

class Solution {
public:
    vector<string> ans;
    vector<int> path;

    void dfs(TreeNode* root) {
        path.push_back(root->val);
        if (!root->left and !root->right) {
            ans.push_back(join(path)); return; 
        }

        
        if (root->left) dfs(root->left), path.pop_back();
        if (root->right) dfs(root->right), path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        path.clear();
        ans.clear();
        if (root) dfs(root);
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    auto tree = from({1, 2, 3, null, 5});
    Solution sol;   
    
    cout << sol.binaryTreePaths(tree);

    return 0;
}
