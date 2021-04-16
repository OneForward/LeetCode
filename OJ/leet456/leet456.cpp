/*
leet456


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
    bool find132pattern(const vector<int>& A) {
        // 枚举 1 O(N)
        int n = A.size();
        stack<int> S; 
        auto max2 = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {
            auto x = A[i];
            if (x < max2) return true; // x 作为 max1： 成功
            while (S.size() and S.top() < x) {
                max2 = S.top(); S.pop(); // 我们希望 max2 尽可能大
            }
            if (x > max2) S.push(x); // x 作为 max3
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.find132pattern({1,2,3,4}) << endl;
    cout << sol.find132pattern({3,1,4,2}) << endl;
    cout << sol.find132pattern({-1,3,2,0}) << endl;
    return 0;
}
