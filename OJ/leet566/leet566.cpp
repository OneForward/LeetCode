/*
leet566


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
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> nums, const int r, const int c) {
        const int R = nums.size(), C = nums[0].size();
        if (R * C != r * c) return nums;

        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < R * C; ++i) {
            ans[i/c][i%c] = nums[i/C][i%C];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.matrixReshape({{1,2}, {3,4}}, 1, 4) << endl;
    cout << sol.matrixReshape({{1,2}, {3,4}}, 2, 4) << endl;
    return 0;
}
