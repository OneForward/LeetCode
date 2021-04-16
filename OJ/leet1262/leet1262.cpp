/*
leet1262


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


class Solution {
public:
    int maxSumDivThree(const vector<int>& nums) {
        // 动态规划
        // x % 3 == 0 时 f(i) = f(i) + x
        // x % 3 == 1 时 f(0) = max(f(0), f(2) + x)
        // x % 3 == 2 时 f(0) = max(f(0), f(1) + x)
        int f[3]{}, g[3];
        for (auto x: nums) {
            auto mod = x % 3;

            for (int i = 0; i < 3; ++i) g[i] = f[i];
            
            for (int i = 0; i < 3; ++i) {
                auto g_complement = g[(3 + i- mod) % 3];
                if (g_complement || mod == i) // 注意初始化时候的判断
                    f[i] = max(g[i], g_complement + x);
            }
            
        }
        return f[0];
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxSumDivThree({3,6,5,1,8}) << endl;
    cout << sol.maxSumDivThree({1,2,3,4,4}) << endl;
    cout << sol.maxSumDivThree({4}) << endl;
    return 0;
}
