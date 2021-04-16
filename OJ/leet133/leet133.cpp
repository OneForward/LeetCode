/*
leet133


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
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* dfs(Node* node, vector<Node*>& v) {
        v[node->val] = new Node(node->val);
        for (auto pi: node->neighbors) {
            if (v[pi->val] == nullptr) dfs(pi, v);
            v[node->val]->neighbors.push_back( v[pi->val] ) ;
        }
        return v[node->val];
    }
    Node* cloneGraph(Node* node) {
        // 4ms
        if (node == nullptr) return nullptr;
        vector<Node*> v(101, nullptr);
        return dfs(node, v);
    }
};

int main(int argc, char const *argv[])
{
    vector<Node*> v(101, nullptr);
    for (int i = 1; i < 100; ++i) {
        v[i] = new Node(i);
    }
    v[1]->neighbors = { v[2], v[3] };
    v[2]->neighbors = { v[1], v[3], v[4], v[5] };
    v[3]->neighbors = { v[1], v[2], v[4] };
    v[4]->neighbors = { v[2], v[3] };
    v[5]->neighbors = { v[2] };
    Solution sol;   
    auto M = sol.cloneGraph(v[1]);
    return 0;
}
