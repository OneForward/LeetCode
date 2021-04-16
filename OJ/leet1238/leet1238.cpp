/*
leet1238


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> g(1<<n);
        for (size_t i = 0; i < (1<<n); i++)
        {
            g[i] = i ^ (i >> 1) ^ start;
        }
        return g;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.circularPermutation(2, 3) << endl;
    cout << sol.circularPermutation(3, 2) << endl;
    return 0;
}
