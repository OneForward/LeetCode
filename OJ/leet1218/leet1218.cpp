/*
leet1218


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int longestSubsequence1(const vector<int>& A, int diff) {
        // 动态规划 TLE
        // f[i] = max { f[j] + 1 | A[i] - A[j] == diff, j < i, j nearest }
        int n = A.size();
        vector<int> f(n);
        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (A[i] - A[j] == diff) {
                    f[i] = f[j] + 1; break;
                }
            }
        }
        return *max_element(f.begin(), f.end()) + 1;
    }
    
    int longestSubsequence(const vector<int>& A, int diff) {
        // 动态规划 320ms
        // f[i] = max { f[j] + 1 | A[i] - A[j] == diff, j < i, j nearest }
        int n = A.size();
        unordered_map<int, int> f;
        using Pair = decltype(f)::value_type;

        for (const auto x: A) {
            f[x] = f[x-diff] + 1;
        }

        return max_element(f.begin(), f.end(), 
                [](const Pair& lft, const Pair& rht) { return lft.second < rht.second;  } 
            )->second;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestSubsequence( {1,2,3,4}, 1 ) << endl;
    cout << sol.longestSubsequence( {1,3,5,7}, 1 ) << endl;
    cout << sol.longestSubsequence( {1,5,7,8,5,3,4,2,1}, -2 ) << endl;
    return 0;
}
