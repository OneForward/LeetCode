/*
leet120


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 12ms
        vector<int> prev, next = {0};
        for (const auto& row: triangle) {
            prev = next;
            next[0] = prev[0] + row[0];
            for (int i = 1; i < prev.size(); ++i) {
                next[i] =  min(prev[i], prev[i-1]) + row[i] ;
            }
            if (next.size() < row.size()) next.push_back(prev.back() + row.back());
        }
        int minVal = INT_MAX;
        for (auto ri: next) minVal = min(minVal, ri);
        return minVal;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> T = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    Solution sol;   
    cout << sol.minimumTotal(T) << endl;
    return 0;
}
