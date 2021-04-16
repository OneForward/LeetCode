/*
leet429


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
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        
        vector<vector<int>> ans;
        queue<Node*> Q; Q.push(root); ans.push_back({root->val});
        while (Q.size()) {
            auto len = Q.size();
            vector<int> v;
            while (len--) {
                auto p = Q.front(); Q.pop();
                for (const auto& child: p->children) {
                    if (child) Q.push(child), v.push_back(child->val);;
                }
            }
            if (v.size()) ans.push_back(v);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << toNrayTree( {1,null,3,2,4,null,5,6} ) << endl;
    cout << sol.levelOrder( toNrayTree( {1,null,3,2,4,null,5,6} ) ) << endl;
    return 0;
}
