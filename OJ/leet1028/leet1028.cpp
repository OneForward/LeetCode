/*
leet1028


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
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

int parseVal(const string& s, int& st) {
    int x = 0;
    while (st < s.size() and s[st] != '-') x = x * 10 + s[st] - '0', st++;
    return x;
}

int parseHeight(const string& s, int& st) {
    int h = 0;
    while (s[st] == '-') h++, st++;
    return h;
}

struct Node
{
    TreeNode* node; int height;
};

Node parse(const string& s, int& st) {
    auto h = parseHeight(s, st);
    auto x = parseVal(s, st);
    return {new TreeNode(x), h};
}

class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        // 栈, O(N)
        stack<Node> S; int st = 0;
        auto [root, h] = parse(s, st);
        S.push({root, h});

        while (st < s.size()) {
            auto [xnode, h] = parse(s, st);
            while (S.size() and S.top().height >= h) S.pop();
            auto [node, height] = S.top();
            if (node->left == nullptr) node->left = xnode;
            else node->right = xnode;
            S.push({xnode, h});
        }
        return root;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.recoverFromPreorder("1-2--3--4-5--6--7") << endl;
    cout << sol.recoverFromPreorder("1-2--3---4-5--6---7") << endl;
    return 0;
}
