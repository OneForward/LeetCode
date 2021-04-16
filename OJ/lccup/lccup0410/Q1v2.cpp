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
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        // 0ms
        if (*max_element(vat.begin(), vat.end()) == 0) return 0;

        auto ceil_divide = [&](int i) {
            return (vat[i] + bucket[i] - 1) / bucket[i];
        };

        auto cmp = [&](int i, int j) {
            return ceil_divide(i) < ceil_divide(j);
        };

        int N = bucket.size(), zero = 0;
        for (auto& b: bucket) if (b == 0) b++, zero++;
        
        priority_queue Q(cmp, vector<int>{});
        for (int i = 0; i < N; i++) Q.push(i);
        
        auto ans = ceil_divide(Q.top()), time = 0;
        while (time < ans) {
            auto i = Q.top();
            bucket[i]++; time++; Q.pop();
            Q.push(i);
            auto tmp = ceil_divide(Q.top());
            ans = min(ans, tmp + time);
        }

        return ans + zero;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.storeWater({9988,5017,5130,2445,9896,9151,3625,7801,608,3283,1386,979,5209,4182,8234,9870,8714,6435,3800,956,4006,5620,7474,1205,6993,3320,1201,7593,905,3816,4522,4560,8027,8219,6686,3779,2141,1240,6504,6612,6921,7329,8145,5745,7652,4340,7933,6246,5157,9447,107,9665,3653,2978,9832,4945,4312,2199,449,8432,3230,8163,800,6547,1110,1194,9384,632,3275,1229,7230,8643,7613,8256,5043,1288,3088,8997,4554,4755,7433,8146,9722,3469,8863,5831,7816,5058,4316,7946,8402,975,2450,4958,9811,9336,21,9309,8999,56}, {9991,6973,7192,9876,9910,9549,3700,8814,1308,9981,9234,7292,7732,8458,8441,9939,9621,7285,7452,2718,6589,7555,8788,3202,7832,4781,8798,9299,2112,9963,8755,7240,9217,8587,6782,9703,8954,3759,6907,7218,7333,8020,8323,5750,9510,8571,8664,8510,9363,9741,8643,9825,4227,8530,9961,8511,8949,7486,9086,9690,5316,9581,9314,8817,7234,8998,9485,5394,7365,1501,7984,9802,9778,8314,7482,7117,5117,9609,8732,9728,9330,8800,9775,6210,8966,7700,8802,7607,8950,9730,9855,1231,5228,5329,9982,9532,3230,9951,9034,8299}) << endl;
    cout << sol.storeWater({1,3}, {0, 0}) << endl;
    cout << sol.storeWater({1,3}, {6,8}) << endl;
    cout << sol.storeWater({9,0,1}, {0,2,2}) << endl;
    return 0;
}
