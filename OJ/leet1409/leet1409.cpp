/*
leet1409


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
    vector<int> processQueries(const vector<int>& queries, int m) {
        // O(MQ), 模拟
        vector<int> L(m);
        iota(L.begin(), L.end(), 1);
        
        vector<int> ans; ans.reserve(queries.size());
        for (const auto& x: queries) {
            auto pos = find(L.begin(), L.end(), x) - L.begin();
            ans.push_back(pos);
            while (pos) L[pos] = L[pos-1], pos--;
            L[0] = x;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.processQueries({3,1,2,1}, 5) << endl;
    cout << sol.processQueries({4,1,2,2}, 4) << endl;
    cout << sol.processQueries({7,5,5,8,3}, 8) << endl;
    return 0;
}
