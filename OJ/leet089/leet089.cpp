/*
leet089


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
    vector<int> grayCode(int n) {
        vector<int> f(1<<n);
        for (int i = 0; i < 1<<n; i++)
        {
            f[i] = i ^ (i >> 1);
        }
        return f;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.grayCode(2) << endl;
    return 0;
}
