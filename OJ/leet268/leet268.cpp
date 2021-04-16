/*
leet268


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
    int missingNumber(vector<int> A) {
        int n = A.size(), ans = n;
        for (int i = 0; i < n; ++i) ans ^= i, ans ^= A[i];
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.missingNumber({3,0,1}) << endl;
    cout << sol.missingNumber({0,1}) << endl;
    cout << sol.missingNumber({1,3,0}) << endl;
    cout << sol.missingNumber({9,6,4,2,3,5,7,0,1}) << endl;
    cout << sol.missingNumber({0}) << endl;
    return 0;
}
