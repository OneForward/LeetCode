/*
leet1128


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(const vector<vector<int>>& dominoes) {
        vector<int> S(100, 0);
        for (const auto& edge: dominoes) {
            int pos;
            if (edge[0] < edge[1]) pos = edge[0]*10 + edge[1];
            else pos = edge[1]*10 + edge[0];
            S[pos]++;
        }
        int sum = 0;
        for (const auto& si: S) sum += si * (si-1) / 2;
        return sum;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.numEquivDominoPairs({{1,2},{2,1},{3,4},{5,6}}) << endl;
    cout << sol.numEquivDominoPairs({{1,2},{2,1},{1,1},{1,2},{2,2}}) << endl;
    return 0;
}
