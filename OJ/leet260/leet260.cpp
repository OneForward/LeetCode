/*
leet260


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
using namespace std;

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}


class Solution {
public:
    vector<int> singleNumber(const vector<int>& nums) {
        int bitmask = 0;
        for (auto vi: nums) bitmask ^= vi;

        auto diff = bitmask & (-bitmask); // right most 1-bit diff of x and y
        
        int x = 0;
        for (auto vi: nums) {
            if (vi & diff) { // y is filetered
                x ^= vi;
            }
        }
        return {x, x^bitmask };
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.singleNumber({1,2,1,3,2,5});
    cout << sol.singleNumber({2,1,2,3,4,1});
    return 0;
}
