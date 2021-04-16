/*
leet313


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
    int nthSuperUglyNumber(int n, const vector<int>& primes) {
        int K = primes.size();
        vector<int> pos(K);

        vector<int> f = {1}; f.reserve(n);
        while (f.size() < n) {
            auto x = INT_MAX;
            for (int k = 0; k < K; ++k) {
                x = min(x, f[pos[k]] * primes[k]);
            }
            f.push_back(x);
            for (int k = 0; k < K; ++k) {
                if (f[pos[k]] * primes[k] <= x) pos[k]++;
            }
        }
        return f.back();
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.nthSuperUglyNumber(12, {2,7,13,19}) << endl;
    return 0;
}
