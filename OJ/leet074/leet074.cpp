/*
leet074


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
    bool searchMatrix(const vector<vector<int>>& M, int target) {
        const int m = M.size(), n = M[0].size();
        int lft = 0, rht = m * n;
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            if (M[mid/n][mid%n] >= target) rht = mid;
            else lft = mid + 1;
        }
        return lft < (m * n) and  M[lft/n][lft%n] == target;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.searchMatrix({{1}}, 2) << endl;
    return 0;
}
