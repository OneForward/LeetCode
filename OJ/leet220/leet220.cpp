/*
leet220


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate1(const vector<int>& nums, int k, int t) {
        // O(N^2)
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j <= i + k && j < nums.size(); ++j) {
                if (abs((long long)nums[i] - nums[j]) <= t) return true;
            }
        }
        return false;
    }
    bool containsNearbyAlmostDuplicate(const vector<int>& nums, int k, int t) {
        // O(N log K)
        set<int> S;
        for (int i = 0; i < nums.size(); ++i) {
            auto s = S.lower_bound(nums[i]);
            if (s != S.end() && *s <= (long long)nums[i] + t) return true;

            if ( s != S.begin() ) {
                s--;
                if ( s != S.end() && *s >= (long long)nums[i] - t) return true;
            }

            S.insert(nums[i]);

            if (S.size() > k) S.erase(nums[i-k]);
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha << sol.containsNearbyAlmostDuplicate({1,2,3,1}, 3, 0) << endl;
    cout << boolalpha << sol.containsNearbyAlmostDuplicate({1,0,1,1}, 1, 2) << endl;
    cout << boolalpha << sol.containsNearbyAlmostDuplicate({1,5,9,1,5,9}, 2, 3) << endl;
    cout << boolalpha << sol.containsNearbyAlmostDuplicate({-1, 2147483647}, 1, 2147483647) << endl;
    cout << boolalpha << sol.containsNearbyAlmostDuplicate({-2147483648, -2147483647}, 3, 3) << endl;
    return 0;
}
