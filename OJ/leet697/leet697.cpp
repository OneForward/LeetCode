/*
leet697


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
    int findShortestSubArray(const vector<int>& nums) {
        struct Tuple
        {
            int freq, lft, rht;
        };
        
        int n = nums.size();
        unordered_map<int, Tuple> Counter;
        for (int i = 0; i < n; ++i) {
            const auto& x = nums[i];
            if (Counter.count(x) == 0) {
                Counter[x] = {1, i, i};
            }
            else {
                auto& tuple = Counter[x];
                tuple.freq++;
                tuple.rht = i;
            }
        }

        int max_freq = 0, max_len = 0;
        for (const auto& [k, v]: Counter) {
            if (v.freq > max_freq) max_freq = v.freq, max_len = v.rht - v.lft + 1;
            else if (v.freq == max_freq)  max_len = min(v.rht - v.lft + 1, max_len);
        }

        return max_len;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findShortestSubArray({1, 2, 2, 3, 1}) << endl;
    cout << sol.findShortestSubArray({1,2,2,3,1,4,2}) << endl;
    return 0;
}
