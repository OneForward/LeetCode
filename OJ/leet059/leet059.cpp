/*
leet059


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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int r = 0, c = 0, cnt = 1;
        for (int x = 0; x <= n / 2; x++)
        {
            for ( c = x; c < n - x; c++) ans[r][c] = cnt++; c--;
            for ( r = x + 1; r < n - x; r++) ans[r][c] = cnt++; r--;
            for ( c = n-x-2; c >= x; c--) ans[r][c] = cnt++; c++;
            for ( r = n-x-2; r >= x + 1; r--) ans[r][c] = cnt++; r++;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.generateMatrix(3) << endl;
    cout << sol.generateMatrix(1) << endl;
    cout << sol.generateMatrix(2) << endl;
    return 0;
}
