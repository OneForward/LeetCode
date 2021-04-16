/*
leet832


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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int C = A[0].size();
        for (auto& row: A) {
            for (size_t c = 0; c < C/2; c++)
            {
                swap(row[c], row[C-c-1]);
            }
            for (auto& x: row) x = 1 - x;
        }
        return A;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   

    return 0;
}
