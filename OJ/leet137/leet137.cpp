/*
leet137


*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        int x = 0, y = 0;
        for (auto&& z: nums) {
            y = ~x & (y ^ z);
            x = ~y & (x ^ z);
        }
        return y;
    }
};

class Solution1 {
public:
    int singleNumber(const vector<int>& v) {
        // all repeat 3 times except some one
        int y = 0, x = 0;
        for (auto vi: v) {
            y = ~x & ( y ^ vi );
            x = ~y & ( x ^ vi );
        }
        return y;
    }
    int singleNumber4Repeats(const vector<int>& v) {
        // all repeat 4 times except some one
        int x = 0, y = 0;
        for (auto vi: v) {
            y ^= vi;
            x = (x & y) | (~y & (x ^ vi));
        }
        return y;
    }
    int singleNumber5Repeats(const vector<int>& v) {
        // all repeat 5 times except some one
        int x = 0, y = 0, z = 0;
        for (auto vi: v) {
            z = ~x & (z ^ vi);
            y = ~x & ( (y & ~vi ) | (vi & ~(y ^ z) ) );
            x = ~y & ~z & ( x ^ vi);
        }
        return z;
    }
};

int main(int argc, char const *argv[])
{
    // vector v = {2,2,3,2 };
    // vector v = {0,1,0,1,0,1, 2,2,2,99 };
    // vector v = {1999,1,1999,1,1999,1, 2,2,2,99 };
    // vector v = {1999,1,1,1999,1999,2,1,1999,1, 2,2,2,99 };

    Solution sol;   
    cout << sol.singleNumber( {1999,1,1999,1,1999,1, 2,2,2,99 } ) << endl;
    // cout << sol.singleNumber4Repeats( {1999,1,1,1999,1999,2,1,1999,1, 2,2,2,99 } ) << endl;
    // cout << sol.singleNumber5Repeats( {2, 1, 1999, 1999,1,1,1999,1999,2,1,1999,1, 2,2,2,99 } ) << endl;

    return 0;
}
