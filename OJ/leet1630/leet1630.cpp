/*
leet1630


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
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(const vector<int>& A, const vector<int>& L, const vector<int>& R) {
        // O(QN), 97%
        auto Q = L.size(), N = A.size();
        vector<bool> ans(Q);
        bool f[505]{};
        for (int i = 0; i < Q; i++)
        {
            auto lft = L[i], rht = R[i];
            if (lft == rht) { ans[i] = true; continue; }

            auto minVal = *min_element(A.begin() + lft, A.begin() + rht + 1);
            auto maxVal = *max_element(A.begin() + lft, A.begin() + rht + 1);
            if ((maxVal - minVal) % (rht - lft)) continue;

            auto d = (maxVal - minVal) / (rht - lft);
            if (d == 0) { ans[i] = true; continue; }

            memset(f, 0, rht - lft + 1);
            for (int j = lft; j <= rht; j++)
            {
                auto nd = A[j] - minVal;
                if (nd % d or f[nd / d]) goto failed;
                f[nd / d] = true;
            }
            success: ans[i] = true;
            failed: ;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.checkArithmeticSubarrays({4,6,5,9,3,7}, {0,0,2}, {2,3,5}) << endl;
    cout << sol.checkArithmeticSubarrays({-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10}, {0,1,6,4,8,7}, {4,4,9,7,9,10}) << endl;
    return 0;
}
