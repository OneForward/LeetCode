/*
leet1052


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
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int maxSatisfied(const vector<int>& customers, const vector<int>& grumpy, int K) {
        // sliding window
        int sum = 0, n = customers.size();
        for (int i = 0; i < n; ++i) { 
            if (grumpy[i] == 0) sum += customers[i];
        }

        int window = 0;
        for (int i = 0; i < K; ++i) { 
            if (grumpy[i] == 1) window += customers[i];
        }
        int max_window = window;
        for (int i = 0; i < n-K; ++i) { 
            if (grumpy[i] == 1) window -= customers[i];
            if (grumpy[i+K] == 1) window += customers[i+K];
            max_window = max(max_window, window);
        }
        return sum + max_window;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxSatisfied({1,0,1,2,1,1,7,5}, {0,1,0,1,0,1,0,1}, 3) << endl;
    return 0;
}
