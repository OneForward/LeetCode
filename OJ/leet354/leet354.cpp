/*
leet354


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
    int maxEnvelopes1( vector<vector<int>> envelopes) {
        // O(N^2) 1456ms
        int n = envelopes.size(), ans = 0;
        vector<int> f(n);
        auto cmp = [&](const vector<int>& v1, const vector<int>& v2) {
            auto w1 = v1[0], h1 = v1[1];
            auto w2 = v2[0], h2 = v2[1];
            return w1 < w2 or (w1 == w2 and h1 < h2);
        };
        auto isok = [&](const vector<int>& v1, const vector<int>& v2) {
            auto w1 = v1[0], h1 = v1[1];
            auto w2 = v2[0], h2 = v2[1];
            return w1 < w2 and h1 < h2;
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (isok(envelopes[i], envelopes[j])) f[j] = max(f[j], f[i]+1), ans = max(ans, f[j]);
            }
        }
        return ans + 1;
    }

    
    int maxEnvelopes( vector<vector<int>> envelopes) {
        // O(N log N) , 最长递增子序列的 O(N log N) 算法
        
        auto cmp = [&](const vector<int>& v1, const vector<int>& v2) {
            auto w1 = v1[0], h1 = v1[1];
            auto w2 = v2[0], h2 = v2[1];
            return w1 < w2 or (w1 == w2 and h1 > h2);
        };

        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> f;
        for (const auto& v: envelopes) {
            auto h = v[1];
            auto pos = lower_bound(f.begin(), f.end(), h);
            if (pos == f.end()) f.push_back(h);
            else *pos = h;
        }
        return f.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxEnvelopes({{5,4},{6,4},{6,7},{2,3}}) << endl;
    cout << sol.maxEnvelopes({{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}}) << endl;
    return 0;
}
