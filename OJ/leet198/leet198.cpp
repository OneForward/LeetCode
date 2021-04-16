/*
leet198


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
using namespace std;

class Solution {
public:
    int rob(const vector<int>& nums) {
        // 0ms, 动态规划
        // f[i] = max(f[i], f[i-2] + A[i])
        int f1 = 0, f2 = 0;
        for (const auto x: nums) {
            auto tmp = f1;
            f1 = max(f1, f2 + x);
            f2 = tmp;
        }
        return f1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.rob({1,2,3,1}) << endl;
    cout << sol.rob({2,7,9,3,1}) << endl;
    return 0;
}
