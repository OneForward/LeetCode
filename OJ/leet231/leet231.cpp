/*
leet231


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        cout << (n & (-n)) << endl;
        cout << (n & (n-1)) << endl;
        return  n and (n & (n-1)) == 0;
    }
};


int main(int argc, char const *argv[])
{
    cout << boolalpha;
    Solution sol;   
    cout << sol.isPowerOfTwo(0) << endl;
    cout << sol.isPowerOfTwo(16) << endl;
    return 0;
}
