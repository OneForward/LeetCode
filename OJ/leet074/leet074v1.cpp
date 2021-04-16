/*
leet074


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& M, int target) {
        // 8ms, O(log (M N))
        if (M.empty()) return false;
        int m = M.size(), n = M[0].size();
        int lft = 0, rht = m * n, mid ;
        while (lft < rht) {
            mid = lft + (rht - lft) / 2;
            if (M[mid/n][mid%n] < target) lft = mid+1;
            else if ( M[mid/n][mid%n] > target ) rht = mid;
            else return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> M = {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int t = 55;
    Solution sol;   
    cout << boolalpha << sol.searchMatrix(M, t) << endl;
    return 0;
}
