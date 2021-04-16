/*
lccup0410


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;



class Solution {
public:
    int storeWater(vector<int> bucket, vector<int> vat) {
        auto ceil_divide = [&](int i) {
            auto f = vat[i] / bucket[i];
            if (vat[i] % bucket[i]) f++;
            return f;
        };

        auto cmp = [&](int i, int j) {
            return ceil_divide(i) < ceil_divide(j);
        };

        priority_queue Q(cmp, vector<int>{});
        int N = bucket.size(), zero = 0;
        for (auto& b: bucket) if (b == 0) b++, zero++;
        for (int i = 0; i < N; i++) Q.push(i);

        auto ans = ceil_divide(Q.top()), f = ans;
        while (true) {
            auto i = Q.top();
            auto fi = ceil_divide(i);
            if (fi == 1) break;
            bucket[i]++;
            auto delta = fi - ceil_divide(i);
            f -= (delta - 1);
            ans = min(ans, f);
            Q.pop(); Q.push(i);
        }

        return ans + zero;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.storeWater({1,3}, {6,8}) << endl;
    cout << sol.storeWater({9,0,1}, {0,2,2}) << endl;
    return 0;
}
