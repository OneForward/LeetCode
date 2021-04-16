/*
leet786


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int> A, int k) {
        // under(x) 返回小于 x 的分数个数 与 最大分数 O(N), 关键函数，细节要注意
        // O(N log N) 二分法
        int n = A.size(); A.push_back(INT_MAX);
        auto under = [&](double x ) -> tuple<int, int, int> {
            int i = -1, cnt = 0; auto maxf = 0.; auto a = 0, b = 0;
            for (int j = 0; j < n; j++)
            {
                while (i < n and  (double)A[i+1] / A[j] < x) ++i;
                if (i == -1) continue;
                cnt += i + 1; 
                auto f =  (double)A[i] / A[j];
                if (f > maxf) {
                    maxf = f; a = A[i]; b = A[j];
                }
            }
            return {cnt, a, b};
        };

        auto lo = 0., hi = 1.;
        while (lo < hi) {
            auto mid = (lo + hi) / 2;
            auto [cnt, a, b] = under(mid);
            // cout << make_tuple(lo, hi, cnt, a, b) << endl;
            if (cnt < k) lo = mid;
            else if (cnt == k) return {a, b};
            else hi = mid;
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.kthSmallestPrimeFraction({1, 2, 3, 5}, 3) << endl;
    cout << sol.kthSmallestPrimeFraction({1, 7}, 1) << endl;
    return 0;
}
