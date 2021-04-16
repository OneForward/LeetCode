/*
lcp018


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
    void countingSort(vector<int>& A, int K) {
        vector<int> C(K);
        for (const auto& x: A) C[x]++;

        int i = 0;
        for (size_t x = 0; x < K; x++)
        {
            while (C[x]) {
                A[i++] = x; C[x]--;
            }
        }
        
    }
    int breakfastNumber(vector<int> staple, vector<int> drinks, int t) {
        // O(N + K)
        const int MOD = 1e9 + 7, K = 1e5+1;
        countingSort(staple, K);
        countingSort(drinks, K);
        int ans = 0, rht = drinks.size() - 1;
        for (const auto& x: staple) {
            while (rht >= 0 and  drinks[rht] + x > t) rht--;
            if (rht == -1) break;
            ans += rht + 1; ans %= MOD;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.breakfastNumber({10,20,5}, {5,5,2}, 15) << endl;
    return 0;
}
