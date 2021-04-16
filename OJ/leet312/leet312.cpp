/*
leet312


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
#include <random>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> A) {
        // O(N^3)
        // f(i, j) 表示开区间 (i, j) 中的答案
        // 使用添加气球的方式求解 f(i, j) = max(f(i, k) + A[i] * A[k] * A[j] + f(k, j) )
        
        A.insert(A.begin(), 1);
        A.push_back(1);

        int n = A.size();
        vector<vector<int>> f(n, vector<int>(n));
        for (int len = 1; len < n; ++len) {
            for (int i = 0; i + len < n; ++i) {
                for (int k = 1; k < len; ++k) {
                    f[i][i+len] = max(f[i][i+len],  f[i][i+k] + A[i] * A[i+k] * A[i+len] + f[i+k][i+len]);
                }
            }
        }

        return f[0][n-1];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxCoins({3,1,5,8} ) << endl;
    return 0;
}
