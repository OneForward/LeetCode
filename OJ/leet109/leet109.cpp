/*
leet109


*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x=0) : val(x), next(nullptr) {}
};

ListNode* from(vector<int>&& v) {
    ListNode* head {new ListNode(0)};
    ListNode* p = head;
    for (auto vi: v) {
        p->next = new ListNode(vi);
        p = p->next;
    }
    return head->next;
}

void disp(ListNode* p) {
    while (p)
    {
        printf("%d -> ", p->val); p = p->next;
    }
    printf("nullptr\n");
}


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

class Solution {
public:
    vector<TreeNode*> v;

    TreeNode* f(int lft, int rht) {
        if (rht == lft) return nullptr;

        int mid = lft + (rht - lft) / 2;
        v[mid]->left = f(lft, mid);
        v[mid]->right = f(mid+1, rht);
        return v[mid];
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // 48ms, 60%
        
        while (head) { 
            v.push_back(new TreeNode(head->val)); 
            head = head->next; 
        }

        return f(0, v.size());
    }
};

int main(int argc, char const *argv[])
{
    // ListNode* l1 = from( {1, 2, 3, 4, 5, 6} ); disp(l1);
    ListNode* l1 = from( {-10, -3, 0, 5, 9} ); disp(l1);

    // vector v = { 10,5,15,null,null,6,20 };
    // vector v = { 1, null, 2, null, 3, 4 };
    // vector v = { 2,1,3 };
    // TreeNode* t1 = from(v); disp(t1);
    
    Solution sol; 
    auto t = sol.sortedListToBST(l1);  disp(t);
    return 0;
}
