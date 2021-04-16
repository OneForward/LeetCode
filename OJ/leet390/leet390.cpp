/*
leet390


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
    int lastRemaining(int n) {
        return f1(n);
    }
    int f1(int n) { 
        if (n == 1) return 1;
        return f2(n/2) * 2;
    }
    int f2(int n) { 
        if (n == 1) return 1;
        return f1(n/2) * 2 + n % 2 - 1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.lastRemaining(2) << endl;
    cout << sol.lastRemaining(3) << endl;
    cout << sol.lastRemaining(9) << endl;
    return 0;
}
