/*
leet075


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
    void sortColors(vector<int>& v) {
        // 4ms, 一趟搜索
        int lft = 0, rht = v.size()-1, p = 0;
        while (p <= rht) {
            if (v[p] == 0) swap(v[p++], v[lft++]); // 奇妙之处在于 p >= lft，因此 v[lft] != 2
            else if (v[p] == 2) swap(v[p], v[rht--]);
            else p++; 
        }
        
    }
    void sortColors2(vector<int>& v) {
        // 0ms, 两趟搜索，计数排序
        int one = 0, zero = 0;
        for (const auto vi: v) {
            if (vi == 0) zero++;
            else if (vi == 1) one++;
        }
        int p = 0;
        while (zero--) v[p++] = 0;
        while (one--)  v[p++] = 1;
        while (p < v.size()) v[p++] = 2;
    }
};

int main(int argc, char const *argv[])
{
    // vector v = { 1,2,0 };
    // vector v = { 1,0,2 };
    vector v = { 2,0,2,1,1,0 };

    Solution sol;   
    sol.sortColors(v);

    for (auto vi: v) cout << vi << ", "; cout << endl;
    return 0;
}
