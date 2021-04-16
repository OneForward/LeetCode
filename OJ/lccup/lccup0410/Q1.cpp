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
        int ans = INT_MAX, n = vat.size();
        if (*max_element(vat.begin(), vat.end()) == 0) return 0;
        const int MAX_V = 1e4;
        for (int i = 1; i < MAX_V; i++) {
            auto sum = i;
            for (int j = 0; j < n; j++) {
                sum += max(0, (vat[j] + i - 1) / i - bucket[j] );
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.storeWater({1,3}, {6,8}) << endl;
    cout << sol.storeWater({9,0,1}, {0,2,2}) << endl;
    return 0;
}
