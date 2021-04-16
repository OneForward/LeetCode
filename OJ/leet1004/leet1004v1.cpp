/*
leet1004


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
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
    int longestOnes(vector<int> A, int K) {
        // sliding window, 双指针法
        // f(l, r) 记录了 A[l, r] 中 0 的个数，
        // 如果 A[r] == 1 则继续向右延伸
        // 否则若 f > K 则左端移动，缩小长度
        // 算法本质: 若以 l 为左端点，右侧 r 最多能延伸到几何
        // 对于 r1, 满足 f(l, r1) = K， f(l, r1+1) = K + 1
        // 则 对任意 r1 < r2:  f(l, r2)  >= f(l, r1+1) = K + 1  恒成立

        int lft = 0, rht = 0, f = 0, ans = 0;
        while (rht < A.size()) {
            if (A[rht] == 0) {
                f++;
                while (f > K) {
                    if (A[lft] == 0) f--;
                    lft++;
                }
            }
            rht++;
            ans = max(ans, rht - lft);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestOnes({1,1,1,0,0,0,1,1,1,1,0}, 2) << endl;
    cout << sol.longestOnes({0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3) << endl;
    return 0;
}
