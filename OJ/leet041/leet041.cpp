/*
leet041

inplace hashing
*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        // 0ms, inplace hashing
        for (int i = 0; i < v.size(); ++i) {
            int vi = v[i];
            while (vi > 0 && vi <= v.size() && vi-1 != i && v[vi-1] != vi) {
                swap(v[i], v[vi-1]); 
                vi = v[i];
            }
        }
        int ans = 0;
        while (ans < v.size() && v[ans]-1 == ans) ans++;
        for (auto vi: v) cout << vi << ", "; cout << endl;
        return ans+1;
    }
};

int main(int argc, char const *argv[])
{
    // vector v = {1, 2, 0};
    vector v = {1, 1};
    // vector v = {3, 4, -1, 1};
    // vector v = {7, 8, 9, 11,12};
    Solution sol;
    cout << sol.firstMissingPositive(v) << endl;

    return 0;
}
