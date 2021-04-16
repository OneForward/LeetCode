/*
leet011


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
    int maxArea(vector<int>&& v) {
        // 双指针, O(N)
        int lft = 0, rht = v.size() - 1, S = 0;
        while (lft < rht) {
            if (v[lft] < v[rht]) {
                S = max(S, v[lft] * (rht - lft) ); lft++;
            }
            else {
                S = max(S, v[rht] * (rht - lft) ); rht--;
            }
        }
        return S;
    }
    int maxArea2(vector<int>&& v) {
        // 暴力搜索, O(N^2)
        int n = v.size(); int S = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)  {
                S = max( min(v[i], v[j]) * (j - i), S );
            }
        }
        return S;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   

    cout << sol.maxArea({1,8,6,2,5,4,8,3,7}) << endl;
    return 0;
}
