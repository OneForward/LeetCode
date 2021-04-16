/*
leet995


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int minKBitFlips1(vector<int> A, int K) {
        // TLE
        int n = A.size(), ans = 0, lft = 0;
        auto check = [&]()  {
            for (int i = lft; i < n; ++i) { 
                if (A[i] == 0) return i; 
            }
            return n;
        };
        auto flip = [&]() {
            for (int i = lft; i < lft + K; ++i) 
                A[i] = 1 - A[i];
            ans++;
        };
        
        while (true) {
            lft = check();
            if (lft > n-K) break;
            flip();
        }
        lft = check();
        return lft == n ? ans : -1;
    }
    int minKBitFlips(vector<int> A, int K) {
        // flip[i] 记录 A[i] 被翻转几次
        // h[i] 提示 A[i] 被“标记”翻转几次
        // 每次更新 flip[i]，若 flip[i] == A[i]，则进入翻转事件，并“标记” h[i+K]
        int n = A.size(), flip = 0, ans = 0;
        vector<int> hint(n);
        for (int i = 0; i < n; ++i) { 
            flip ^= hint[i];
            if (A[i] == flip) {
                ans++;
                flip ^= 1;
                if (i + K > n) return -1;
                if (i + K < n) hint[i+K] ^= 1;
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minKBitFlips({0,1,0}, 1) << endl;
    cout << sol.minKBitFlips({1,1,0}, 2) << endl;
    cout << sol.minKBitFlips({0,0,0,1,0,1,1,0}, 3) << endl;
    return 0;
}
