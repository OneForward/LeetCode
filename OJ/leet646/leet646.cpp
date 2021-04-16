/*
leet646


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

using Vint = vector<int>;
template<> struct std::less<Vint>
{
    bool operator()(const Vint& lft, const Vint& rht) const {
        return lft[0] < rht[0] or (lft[0] == rht[0] and lft[1] < rht[1]);
    }
};

bool isLess(const Vint& lft, const Vint& rht) { return lft[1] < rht[0]; }

class Solution {
public:
    int findLongestChain(vector<vector<int>> A) {
        sort(A.begin(), A.end());
        auto n = A.size();
        vector<int> f(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (isLess(A[i], A[j])) f[j] = f[i] + 1;
            }
        }
        auto ans = *max_element(f.begin(), f.end()) + 1;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.findLongestChain( {{1,2}, {2,3},{3,4}} )    << endl;
    cout << sol.findLongestChain( {{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}} )    << endl;
    // vector<Vint> v = {{1,2}, {-1, 4}, {-1, 3}};
    // sort(v.begin(), v.end());
    // cout << v;
    return 0;
}
