/*
leet813


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
    double largestSumOfAverages(const vector<int>& A, int K) {
        auto n = A.size();
        vector<double> f(n+1), g; auto sum = 0.;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            f[i+1] = sum / (i + 1);
        }
        for (int k = 1; k < K; ++k) {
            g = f;
            for (int i = k; i < n; ++i) {
                auto sum = 0., curmax = 0.;
                for (int j = i; j >= k; --j) {
                    sum += A[j];
                    curmax = max(curmax, g[j] + sum / (i - j + 1));
                }
                f[i+1] = curmax;
            }
        }
        return f[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.largestSumOfAverages({9,1,2,3,9}, 3) << endl;
    cout << sol.largestSumOfAverages({1,2,3,4,5,6,7}, 4) << endl;
    return 0;
}
