/*
leet222


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
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

TreeNode* from(vector<int>& v) {
    
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


class Solution1 {
public:
    int countNodes(TreeNode* root) {
        // 68ms, O(N)
        if (root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

class Solution {
public:

    int height(TreeNode* root) {
        int h = -1;
        while (root) h++, root = root->left;
        return h;
    }
    bool has_index(TreeNode* root, int idx, int n) {
        while (root) {
            if (idx >= n/2) idx -= n/2, root = root->right;
            else root = root->left;
            n /= 2;
        }
        return n == 0;
    }
    int countNodes(TreeNode* root) {
        // 44ms, O(log^2 N)
        if (root == nullptr) return 0;
        int h = height(root), n = (1 << h);
        
        int lft = 0, rht = n;
        while (lft < rht) {
            int mid = (lft + rht) / 2;
            if (has_index(root, mid, n)) lft = mid + 1 ;
            else rht = mid;
        }
        return n + lft - 1;
    }
};

int main(int argc, char const *argv[])
{   
    vector v = { 1, 2, 3, 4, 5, 6 };
    TreeNode* t = from(v); disp(t);
    Solution sol;   
    cout << sol.countNodes(t) << endl;
    return 0;
}
