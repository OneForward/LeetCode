/*
leet560


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
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int subarraySum(const vector<int>& nums, int k) {
        unordered_map<int, int> M;
        M[0] = 1;

        int ans = 0, pre = 0;
        for (const auto& x: nums) {
            pre += x; 
            if (M.find(pre-k) != M.end()) {
                ans += M[pre-k];
            }
            M[pre]++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.subarraySum({1,1,1}, 2) << endl;
    cout << sol.subarraySum({-1,-1,1}, 0) << endl;
    cout << sol.subarraySum({1,2,3}, 3) << endl;
    return 0;
}
