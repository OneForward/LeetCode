/*
offer059


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        // 单调 deque
        deque<int> Q; vector<int> ans;
        for (int i = 0; i < k; ++i) { 
            while (!Q.empty() and nums[Q.back()] <= nums[i]) Q.pop_back();
            Q.push_back(i);
        }
        if (!Q.empty()) ans.push_back(nums[Q.front()]);
        
        for (int i = k; i < nums.size(); ++i) { 
            if (Q.front() + k <= i) Q.pop_front();
            while (!Q.empty() and nums[Q.back()] <= nums[i]) Q.pop_back();
            Q.push_back(i); 
            ans.push_back(nums[Q.front()]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxSlidingWindow({1,3,-1,-3,5,3,6,7}, 3) << endl;
    cout << sol.maxSlidingWindow({}, 0) << endl;
    cout << sol.maxSlidingWindow({1,-1}, 1) << endl;
    cout << sol.maxSlidingWindow({7, 2, 4}, 2) << endl;
    cout << sol.maxSlidingWindow({1,3,1,2,0,5}, 3) << endl;
    return 0;
}
