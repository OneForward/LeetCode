/*
leet719


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

    int smallestDistancePair(vector<int> A, int k) {
        // 滑动窗口 + 二分搜索, O(N log R), R = range(A)
        sort(A.begin(), A.end());

        const auto N = A.size();
        auto howManyPairsLessThan = [&](int dist) {
            size_t rht = 1; size_t cnt = 0;
            for (size_t lft = 0; lft < N; lft++)
            {
                while (rht < N and A[rht] - A[lft] <= dist) rht++;
                cnt += rht - lft - 1;
            }
            return cnt;
        };

        int rht = A.back() - A.front() + 1, lft = 0;

        while (lft < rht) {
            auto mid = (lft + rht)  / 2;
            if (howManyPairsLessThan(mid) >= k) rht = mid;
            else lft = mid + 1;
        }
        return lft;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.smallestDistancePair({1,3,1}, 1) << endl;
    cout << sol.smallestDistancePair({1,6,1}, 3) << endl;
    return 0;
}
