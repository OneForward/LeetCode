/*
leet421


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
    int findMaximumXOR1(const vector<int>& nums) {
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            ans <<= 1;
            auto curXor = ans | 1;
            unordered_set<int> S;
            for (const auto& x: nums) S.insert(x >> i);
            for (const auto& x: S) {
                if (S.count(curXor ^ x)) { ans = curXor; break; }
            }
        }
        return ans;
    }
    int findMaximumXOR(const vector<int>& nums) {
        // 80ms, O(N log N)
        // 从最高位开始，逐位向低处检查
        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            ans <<= 1;
            auto curXor = ans | 1; // candidate 
            unordered_set<int> S;
            for (const auto& x: nums) {
                if (S.count(curXor ^ (x >> i))) { ans = curXor; break; }
                S.insert(x >> i);
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findMaximumXOR({3, 10, 5, 25, 2, 8}) << endl;
    cout << sol.findMaximumXOR({8, 10, 2}) << endl;
    return 0;
}
