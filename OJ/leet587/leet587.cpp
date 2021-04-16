/*
leet587

凸包问题
Convex Hull
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
    vector<vector<int>> outerTrees(vector<vector<int>> P) {
        auto cmp = [&](const vector<int>& p1, const vector<int>& p2) {
            return p1[0] < p2[0] or (p1[0] == p2[0] and p1[1] < p2[1]);
        };

        auto ok = [&](const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) {
            return (p2[0] - p1[0]) * (p3[1] - p2[1]) < (p2[1] - p1[1]) * (p3[0] - p2[0]) ;
        };
        auto n = P.size();
        sort(P.begin(), P.end(), cmp);
        
        vector<int> S(n+5); int top = 0;
        vector<bool> used(n);

        for (int i = 0; i < n; ++i) {
            while (top >= 2 and ok(P[S[top-1]], P[S[top]], P[i])) used[S[top--]] = false;
            used[i] = true; S[++top] = i;
        }

        used[0] = false;
        for (int i = n - 1; i >= 0; --i) {
            if ( used[i] ) continue;
            while (top >= 2 and ok(P[S[top-1]], P[S[top]], P[i])) used[S[top--]] = false;
            used[i] = true; S[++top] = i;
        }
        vector<vector<int>> ans(top-1);
        for (int i = 1; i < top; ++i) ans[i-1] = P[S[i]];
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.outerTrees({{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}}) << endl;
    return 0;
}
