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
        // O(N log N)
        int n = A.size(), fi, gi;
        stack<int> S;
        vector<int> L;
        auto cmp = [&](const auto& i, const auto& j) {
            return A[i] > A[j];
        };

        for (int i = 0; i < n; i++)
        {
            fi = 0, gi = n;
            // 找到左边倒数第一个大于自己的数
            auto x = A[i];
            while (S.size() and A[S.top()] <= x) S.pop();
            if (S.size()) fi = S.top();
            S.push(i); 

            // 找到左边第一个比自己小的数
            auto pos = upper_bound(L.begin(), L.end(), i, cmp);
            if (pos == L.end()) L.push_back(i);
            else gi = *pos;
            if (fi > gi) return true;
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
