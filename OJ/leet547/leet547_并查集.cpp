/*
leet547


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

vector<int> P;

int find(int i) {
    if (P[i] < 0)  return i;
    return P[i] = find(P[i]);
}

void merge(int i, int j) {
    int r1 = find(i), r2 = find(j);
    if (r1 == r2) return;
    if (P[r1] < P[r2]) P[r1] += P[r2], P[r2] = r1;
    else P[r2] += P[r1], P[r1] = r2;
}


class Solution {
public:
    int findCircleNum(const vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        P = vector<int>(n, -1);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i+1; j < n; j++)
            {
                if (isConnected[i][j]) {
                    merge(i, j);
                }
            }   
        }
        int ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (P[i] < 0) ans++;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.findCircleNum({{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}}) << endl;
    cout << sol.findCircleNum({{1,1,1},{1,1,1,},{1,1,1},}) << endl;
    return 0;
}
