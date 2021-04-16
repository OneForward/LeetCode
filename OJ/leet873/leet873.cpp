/*
leet873


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

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}


class Solution {
public:
    int lenLongestFibSubseq(const vector<int>& A) {
        // 244ms, 动态规划 Time O(N^2) Space O(N^2)
        // f(i, j) = f(j, k) + 1; i > j > k, A[i] = A[j] + A[k]
        int n = A.size(), ans = 0;
        vector<vector<int>> f(n, vector<int>(n));
        unordered_map<int, int> M;
        for (int i = 0; i < n; ++i) M[A[i]] = i;
        
        for (int i = 2; i < n; ++i) { 
            for (int j = 0; j < i; ++j) { 
                if (A[i] - A[j] < A[j]) {
                    auto p = M.find(A[i] - A[j]);
                    if (p != M.end()) {
                        f[i][j] = f[j][p->second] + 1 ;
                        ans = max(ans, f[i][j]);
                    }
                }
            }
        }   
        return ans ? ans + 2 : 0;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.lenLongestFibSubseq({1,2,3,4,5,6,7,8}) << endl;
    cout << sol.lenLongestFibSubseq({1,3,7,11,12,14,18}) << endl;
    return 0;
}
