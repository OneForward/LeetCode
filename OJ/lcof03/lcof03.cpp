/*
lcof.03


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
    int findRepeatNumber(vector<int> A) {
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] == i) continue;
            auto x = A[i];
            if (A[x] == x) 
                return x;
            while (A[x] != x) {
                auto y = A[x];
                A[x] = x; x = y;
            }
            // return x;
        }
        return 0;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findRepeatNumber({2, 3, 1, 0, 2, 5, 3}) << endl;
    return 0;
}
