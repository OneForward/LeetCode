/*
leet219


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        // 60ms
        unordered_map<int, int> M;
        for (int i = 0; i <= k && i < nums.size(); ++i) { 
            M[nums[i]]++;
            if (M[nums[i]] > 1) return true;
        }
        for (int i = k+1; i < nums.size(); ++i) {
            M[nums[i-k-1]]--;
            M[nums[i]]++;
            if (M[nums[i]] > 1) return true;
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha << sol.containsNearbyDuplicate({1,2,3,1}, 3) << endl;
    cout << boolalpha << sol.containsNearbyDuplicate({1,0,1,1}, 1) << endl;
    cout << boolalpha << sol.containsNearbyDuplicate({1,2,3,1,2,3}, 2) << endl;
    return 0;
}
