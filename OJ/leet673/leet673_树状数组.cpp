/*
leet673


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
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;


struct Pair
{
    int max = 0, cnt = 1;

    void merge(const Pair& p2) {
        auto [max2, cnt2] = p2;
        if (max and max == max2) cnt += cnt2;
        else if (max < max2) {
            max = max2; cnt = cnt2;
        }
    }
    
    friend ostream& operator<< (ostream& os, const Pair& p) {
        os << "{ " << p.max << ", " << p.cnt << " }";
        return os;
    }
};

inline int lowbit(int x) { return x & -x; }

class Solution {
public:
    int findNumberOfLIS(const vector<int>& A) {
        // O(N log N), 树状数组
        int n = A.size();
        vector<Pair> tree(n+1);
        
        auto S = A; sort(S.begin(), S.end()); Pair ans{};

        for (const auto& x: A) {
            auto pos = lower_bound(S.begin(), S.end(), x) - S.begin();
            auto before = Pair{};
            // 对所有小于 x 的数字 ai：merge({a1, a2, .., am}), 即
            // 1. 找到最大的 max 2. 合并长度为 max 的 cnt(求和)
            // 然后 x->max = max+1, x->cnt = cnt;
            for (int t = pos; t >= 1; t -= lowbit(t)) before.merge(tree[t]);
            before.max++; 
            for (int t = pos+1; t <= n; t += lowbit(t)) tree[t].merge(before);
            ans.merge(before);
        }
        // cout << tree << endl;
        return ans.cnt;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findNumberOfLIS({1,3,5,4,7}) << endl;
    cout << sol.findNumberOfLIS({2,2,2,2,2}) << endl;
    cout << sol.findNumberOfLIS({1,2,4,3,5,4,7,2}) << endl;
    cout << sol.findNumberOfLIS({2, 1}) << endl;
    return 0;
}
