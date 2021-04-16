/*
leet1043


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
    int maxSumAfterPartitioning(const vector<int>& A, int K) {
        int N = A.size();
        vector<int> f(N+1); 
        for (int n = 0; n < N; ++n) {
            auto y = 0 , curmax = 0;
            for (int i = n; i >= max(n-K+1, 0); --i) {
                curmax = max(curmax, A[i]);
                y = max(y, (n - i + 1) * curmax + f[i] );
            }
            f[n+1] = y;
        }
        return f[N];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxSumAfterPartitioning({1,15,7,9,2,5,10}, 3) << endl;
    return 0;
}
