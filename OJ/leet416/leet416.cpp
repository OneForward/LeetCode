/*
leet416


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
#include <numeric>
using namespace std;

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}

class Solution1 {
public:
    bool search(vector<int>& nums, int target, vector<int>& v) {
        if (nums.empty()) return true;

        auto x = nums.back(); nums.pop_back();
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] + x <= target) {
                v[i] += x;
                if (search(nums, target, v)) return true;
                else v[i] -= x;
            }
            if (v[i] == 0) break;
        }
        nums.push_back(x);
        return false;
    }
    bool canPartition(const vector<int>& nums) {
        // 4ms, 递归解法
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;

        int target = sum / 2;
        vector<int> v(2);
        vector<int> copy = nums;
        return search(copy, target, v );
    }
};

class Solution {
public:

    bool canPartition(const vector<int>& A) {
        // 540ms, 0-1背包解法
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 2) return false;

        int target = sum / 2;
        vector<bool> f(target+1, false);
        for (int i = 0; i < A.size(); ++i) {
            for (int j = target; j >= A[i]; --j) { 
                if (A[i] == j) f[j] = true;
                f[j] = f[j] || f[j-A[i]];
            }
            // cout << f;
        }
        return f[target];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha << sol.canPartition({1,5,11,5}) << endl;
    cout << boolalpha << sol.canPartition({1,2,3,5}) << endl;
    cout << boolalpha << sol.canPartition({1,2,5}) << endl;
    return 0;
}
