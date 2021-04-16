/*
leet1004


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int longestOnes(const vector<int>& A, int K) {
        int lft = 0, n = A.size(), ans = 0;
        for (int rht = 0; rht < n; rht++)
        {
            if (A[rht] == 0) {
                if (K == 0) {
                    while (A[lft] == 1) lft++;
                    lft++;
                }
                else K--;
            }
            ans = max(ans, rht - lft + 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestOnes({1,1,1,0,0,0,1,1,1,1,0}, 2) << endl;
    cout << sol.longestOnes({0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3) << endl;
    return 0;
}
