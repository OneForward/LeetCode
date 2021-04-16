/*
leet054


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
    vector<int> spiralOrder(const vector<vector<int>>& M) {
        vector<int> v; int R = M.size(), C = M[0].size();
        int r = 0, c = 0; const int RC = R * C;
        for (int x = 0; ; x++)
        {
            for (c = x; c < C-x; c++) v.push_back(M[r][c]); c--;
            if (v.size() == RC) break;
            for (r = x+1; r < R-x; r++) v.push_back(M[r][c]); r--;
            if (v.size() == RC) break;
            for (c = C-x-2; c >= x; c--) v.push_back(M[r][c]); c++;
            if (v.size() == RC) break;
            for (r = R-x-2; r > x; r--) v.push_back(M[r][c]); r++;
            if (v.size() == RC) break;
        }
        return v;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.spiralOrder( {{1,2,3},{4,5,6},{7,8,9}} ) << endl;
    cout << sol.spiralOrder( {{1,2,3,4},{5,6,7,8},{9,10,11,12}} ) << endl;
    return 0;
}
