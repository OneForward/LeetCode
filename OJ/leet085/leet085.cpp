/*
leet085


*/


#include <iostream>
#include <vector>
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
    int maximalRectangle(vector<vector<char>>& M) {
        // 52ms
        if (M.empty()) return 0;
        int m = M.size(), n = M[0].size(), ans = 0;
        vector<int> v(n), lft(n), rht(n); stack<int> S; 
        for (auto row: M) {
            for (int i = 0; i < n; ++i) {
                if (row[i] == '1') v[i]++; 
                else v[i] = 0;
            }   
            S = {};
            for (int i = 0; i < n; ++i) {
                while (!S.empty() && v[S.top()] >= v[i]) S.pop();
                lft[i] = S.empty() ? -1 : S.top();
                S.push(i); 
            }
            S = {};
            for (int i = n-1; i >= 0; --i) {
                while (!S.empty() && v[S.top()] >= v[i]) S.pop();
                rht[i] = S.empty() ? n : S.top();
                S.push(i); 
            }
            for (int i = 0; i < n; ++i) {
                ans = max(ans, v[i] * (rht[i] - lft[i] - 1) );
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    // vector<vector<char>> matrix = {
    //     {'1', '1'},
    //  };
    // vector<vector<char>> matrix = {
    //     {'1','0','1','0','0'},
    //     {'1','0','1','1','1'},
    //     {'1','1','1','1','1'},
    //     {'1','0','0','1','0'}
    // };
    // vector<vector<char>> matrix = {
    //     {'0','0','0','1','0','1','1','1'},
    //     {'0','1','1','0','0','1','0','1'},
    //     {'1','0','1','1','1','1','0','1'},
    //     {'0','0','0','1','0','0','0','0'},
    //     {'0','0','1','0','0','0','1','0'},
    //     {'1','1','1','0','0','1','1','1'},
    //     {'1','0','0','1','1',' 0','0','1'},
    //     {'0','1','0','0','1','1','0','0'},
    //     {'1','0','0','1','0','0','0','0'}
    //  };
    vector<vector<char>> matrix = {
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'}
     };
    Solution sol;   

    cout << sol.maximalRectangle(matrix) << endl;
    return 0;
}
