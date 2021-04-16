/*
leet495


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
    int findPoisonedDuration(const vector<int>& timeSeries, int duration) {
        // O(N)
        if (timeSeries.empty()) return 0;
        
        int lo = timeSeries[0], hi = lo + duration, ans = duration;
        for (const auto& x: timeSeries) {
            if (x > hi) lo = x, hi = lo + duration, ans += duration;
            else if (hi < x + duration) ans += x + duration - hi, hi = x + duration;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findPoisonedDuration({1,2}, 2) << endl;
    cout << sol.findPoisonedDuration({1,4}, 2) << endl;
    cout << sol.findPoisonedDuration({1,2,3,4,5}, 5) << endl;
    cout << sol.findPoisonedDuration({}, 5) << endl;
    return 0;
}
