/*
leet480


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

#include "../utils/LeetCpp.utils.hpp"

class Solution {
public:
    vector<double> medianSlidingWindow(const vector<int>& A, int k) {
        // O(N log K), RBTree, MultiSet, 48ms, 15MB
        int n = A.size();
        vector<double> ans(n-k+1);
        multiset<int> S(A.begin(), A.begin()+k);
        auto mid = next(S.begin(), k/2);
        auto diff = k % 2 - 1;

        for (int i = k; ; ++i) { 
            auto midVal = (*mid + (double)*next(mid, diff)) / 2.;
            ans[i-k] = midVal;

            if (i == n) break;

            S.insert(A[i]);
            // 以下这个控制中位数指针转移的操作非常得精妙
            if (A[i] < *mid)  mid--;
            if (A[i-k] <= *mid)  mid++;
            S.erase(S.lower_bound(A[i-k])); // 只删除一个值！！
        }
        
        return ans;
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.medianSlidingWindow({1,3,-1,-3,5,3,6,7}, 3) << endl;
    cout << sol.medianSlidingWindow({1,2,3,4,2,3,1,4,2}, 3) << endl;
    return 0;
}
