/*
leet116


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

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        // 36ms
        if (root == nullptr || root->left == nullptr) return root;
        root->left->next = root->right;
        if (root->next) root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   

    return 0;
}
