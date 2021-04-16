/*
leet264


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
    int nthUglyNumber(int n) {
        vector<int> A = {1}; A.reserve(n);
        int M[][2] {{0, 2}, {0, 3}, {0, 5}};
        while (A.size() < n) {
            auto x = INT_MAX;
            for (auto&& [pos, v]: M ) {
                if (x > A[pos] * v ) x = A[pos] * v;
            }
            A.push_back(x); 
            
            for (auto& [pos, v]: M ) {
                if (A[pos] * v <= x )  pos++;
            }
        }
        return A.back();
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.nthUglyNumber(10) << endl;
    return 0;
}
