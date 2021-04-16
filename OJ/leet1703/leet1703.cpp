/*
leet1703


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
    int minMoves1(const vector<int>& A, int k) {
        // O(Nk)
        // f[i] : 第 i 个 1 的位置
        vector<int> f;
        for (size_t i = 0; i < A.size(); i++)
            if (A[i]) f.push_back(i-f.size());

        int ans = INT_MAX;
        int lft = 0, rht = k;
        while (rht <= f.size()) {
            auto mid = (lft + rht) / 2;
            auto sum = 0;
            for (int i = lft; i < rht; i++)
            {
                sum += abs(f[i]-f[mid]);
            }
            ans = min(sum, ans);
            lft++; rht++;
        }
        return ans;
    }
    int minMoves(const vector<int>& A, int K) {
        // O(N)
        // P[i] : 第 i 个 1 的位置，不必存储
        // f[i] = P[i] - i

        vector<int> f;
        for (size_t i = 0; i < A.size(); i++)
            if (A[i]) f.push_back(i-f.size());

        int mid1 = K / 2, rht = K, sum = 0;
        for (int i = 0; i < rht; i++) {
            sum += abs(f[i] - f[mid1]);
        }

        int ans = sum, mid2 = (K + 1) / 2 ;

        while (rht < f.size()) {
            sum += f[rht] + f[rht - K]  - f[mid1] - f[mid2];
            ans = min(ans, sum);
            mid1++, mid2++, rht++;
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minMoves({1,0,0,1,0,1}, 2) << endl;
    cout << sol.minMoves({1,0,0,0,0,0,1,1}, 3) << endl;
    cout << sol.minMoves({1,1,0,1}, 2) << endl;
    cout << sol.minMoves({1,0,0,1,0,1,1,1,0,1,1}, 7) << endl;
    cout << sol.minMoves({0,1,0,0,1,1,0,1,0,1,1,1,1,0,1,0}, 7) << endl;
    cout << sol.minMoves({0,1,1,0,0,1,0,0,0}, 3) << endl;
    return 0;
}
