/*
leet698


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
    // 16ms, 剪枝
    bool canPartitionKSubsets(vector<int> A, int k) {
        auto sum = reduce(A.begin(), A.end(), 0);
        if (sum % k) return false;

        auto max = *max_element(A.begin(), A.end());
        if (max > sum / k) return false;
        
        return f(A, sum / k, k);
    }

    bool f(vector<int> A, int target, int k) {
        if (k == 1) return true;
        int n = A.size();
        for (int i = 1<<(n-1); i < (1<<n); i++)
        {
            auto sum = 0;
            for (int x = 0; (1<<x) <= i; x++)
            {
                if ((1<<x) & i) sum += A[x];
            }
            if (sum == target) {
                vector<int> B;
                for (int x = 0; (1<<x) <= i; x++)
                {
                    if (((1<<x) & i) == 0) B.push_back(A[x]);
                }
                auto ok = f(B, target, k-1);
                if (ok) return true;
            }
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.canPartitionKSubsets({4, 3, 2, 3, 5, 2, 1}, 4) << endl;
    return 0;
}
