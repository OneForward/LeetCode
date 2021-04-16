/*
leet698


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
#include <numeric>
using namespace std;

class Solution {
public:
    int target;
    bool search(vector<int>& B, vector<int>& nums) {
        if (nums.empty()) return true;

        auto v = nums.back(); nums.pop_back();
        for (auto& bucket: B) {
            if (bucket + v <= target) {
                bucket += v;
                if (search(B, nums)) return true;
                bucket -= v;
            }
            if (bucket == 0) break;
        }
        nums.push_back(v);
        return false;
    }
    bool canPartitionKSubsets(const vector<int>& vs, int k) {
        // 4ms
        vector<int> nums = vs;
        if (k == 1) return true;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;

        target = sum / k;

        sort(nums.begin(), nums.end());
        if (nums.back() > target) return false;

        vector<int> B(k); // buckets

        return search(B, nums);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha << sol.canPartitionKSubsets({4, 3, 2, 3, 5, 2, 1}, 4);
    // multiset<int> S = {2, 5, 4, 3, 3, 1, 1, 1};
    // for (auto si: S) cout << si << ", "; cout << endl;

    // S.erase(1);
    // for (auto si: S) cout << si << ", "; cout << endl;

    return 0;
}
