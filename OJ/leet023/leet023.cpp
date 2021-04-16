/*
leet023


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
    ListNode* mergeKLists(vector<ListNode*> lists) {
        using NodePtr = ListNode*;
        auto cmp = [](const NodePtr& lft, const NodePtr& rht) {
            return lft->val >= rht->val;
        };
        priority_queue<NodePtr, vector<NodePtr>, decltype(cmp)> Q(cmp);
        for (auto&& p: lists) if (p) Q.push(p);
        ListNode Head; auto curr = &Head;
        while (Q.size()) {
            auto p = Q.top(); Q.pop();
            curr->next = p; curr = p;
            if (p->next) Q.push(p->next);
        }
        return Head.next;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.mergeKLists( {
        toList({1,4,5}),
        toList({1,3,4}),
        toList({2,6})
        }) << endl;
    return 0;
}
