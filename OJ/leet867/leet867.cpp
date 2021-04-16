/*
leet867


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        const auto R = A.size(), C = A[0].size();
        vector<vector<int>> AT(C, vector<int>(R));
        for (size_t c = 0; c < C; c++)
        {
            for (size_t r = 0; r < R; r++)
            {
                AT[c][r] = A[r][c];
            }
        }
        return AT;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   

    return 0;
}
