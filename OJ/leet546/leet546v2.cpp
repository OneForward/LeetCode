/*
leet546

区间DP

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
    int removeBoxes(const vector<int>& A) {
        int n = A.size();
        int M[100][100][100]{};

        function<int(int, int, int)> f = [&] (int i, int j, int k) {
            if (i > j) return 0;
            if (i == j) return k * k;
            if (M[i][j][k]) return M[i][j][k];
            
            auto ni = i, ki = k;
            while (ni <= j and A[ni] == A[i]) ni++, ki++;
            auto x = ki * ki + f(ni+1, j, 1) ,  pi = ni;
            for ( ;ni <= j; ++ni) {
                if (A[ni] == A[i]) x = max(x, f(pi+1, ni-1, 1) + f(ni, j, ki+1) );
            }
            return M[i][j][k] = x;
        };

        return f(0, n-1, 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.removeBoxes( {1,3,2,2,2,3,4,3,1}  ) << endl;
    cout << sol.removeBoxes( {9, 5, 3, 5, 3, 3, 9, 8, 8, 5, 3, 9}  ) << endl;
    return 0;
}
