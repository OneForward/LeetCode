/*
leet070


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
    int climbStairs(int n) {
        // 0ms
        int a = 1, b = 0, t;
        while (n--) {
            t = a; a += b; b = t;
        }
        return a;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    for (auto n: {1, 2, 3, 4, 5, 6, 7}) {
        cout << "n = " << n << ", " << sol.climbStairs(n) << endl;
    }
    return 0;
}
