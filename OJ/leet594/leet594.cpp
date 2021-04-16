/*
leet594


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int findLHS(const vector<int>& nums) {
        // O(N)
        unordered_map<int, int> M; 
        for (const auto& x: nums) M[x]++;
        int ans = 0;
        for (const auto& [x, cnt]: M) {
            if (M.find(x-1) != M.end()) ans = max(ans, M[x]+M[x-1]);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findLHS({1,3,2,2,5,2,3,7}) << endl;
    cout << sol.findLHS({1,2,3,4}) << endl;
    cout << sol.findLHS({1,1,1,1}) << endl;
    return 0;
}
