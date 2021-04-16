/*
leet378


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
    int kthSmallest(const vector<vector<int>>& M, int k) {
        // O( N log Range )
        int n = M.size();              

        auto check = [&] (int x) {
            auto cnt = 0, r = n-1, c = 0;
            while (r >= 0 and c < n) {
                if (M[r][c] <= x) c++, cnt += r + 1;
                else r--;
            }
            return cnt;
        };

        auto lft = M[0][0], rht = M[n-1][n-1] + 1;
        while (lft < rht) {
            auto mid = lft + (rht - lft) / 2;
            if (check(mid) >= k) rht = mid;
            else lft = mid + 1;
        }
        return lft;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.kthSmallest({{1,5,9},{10,11,13},{12,13,15}}, 8) << endl;
    cout << sol.kthSmallest({{-5}}, 1) << endl;
    return 0;
}
