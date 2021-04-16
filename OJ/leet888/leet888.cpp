/*
leet888


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(const vector<int>& A, const vector<int>& B) {
        int sumA = 0, sumB = 0, start = 100005;
        vector<bool> M(200010);
        for (const auto& ai: A) { 
            M[ai+start] = true;
            sumA += ai;
        }
        for (const auto& bi: B) { 
            sumB += bi;
        }
        int diff = (sumA - sumB) / 2;
        for (const auto& bi: B) { 
            if (M[bi+diff+start]) return {bi+diff, bi};
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.fairCandySwap({1,1}, {2,2}) << endl;
    cout << sol.fairCandySwap({1,2}, {2,3}) << endl;
    cout << sol.fairCandySwap({2}, {1,3}) << endl;
    cout << sol.fairCandySwap({1,2,5}, {2,4}) << endl;
    return 0;
}
