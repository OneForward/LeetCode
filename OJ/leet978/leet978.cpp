/*
leet978


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;


inline int sgn(int x, int y) {
    if (x == y) return 0;
    if (x < y) return -1;
    return 1;
}

class Solution {
public:
    int maxTurbulenceSize(const vector<int>& A) {
        int n = A.size();
        if (n <= 1) return n;

        int prev = 0, curr; int len = 1, ans = 1;
        for (int i = 1; i < n; ++i) { 
            curr = sgn(A[i], A[i-1]);
            if (prev * curr == -1) len++;
            else len = curr == 0 ? 1 : 2;
            prev = curr; ans = max(ans, len);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   

    cout << sol.maxTurbulenceSize( {9,4,2,10,7,8,8,1,9} ) << endl;
    cout << sol.maxTurbulenceSize( {4,8,12,16} ) << endl;
    cout << sol.maxTurbulenceSize( {4,8} ) << endl;
    cout << sol.maxTurbulenceSize( {4} ) << endl;
    cout << sol.maxTurbulenceSize( {4, 4} ) << endl;
    cout << sol.maxTurbulenceSize( {4, 4, 4} ) << endl;
    return 0;
}
