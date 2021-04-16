/*
leet1438


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
    int longestSubarray(const vector<int>& A, int limit) {
        // O(N log N)
        // 注意 multiset 中， S.erase(value_T key) 会移除所有值为 key 的元素
        // 使用 S.erase(S.lower_bound( key )) 来确保只移除一个元素（保证了 key 存在的时候）
        // 或使用 find 和 erase 结合
        multiset<int> S;
        int lft = 0, ans = 0;
        for (int rht = 0; rht < A.size(); ++rht) {
            S.insert(A[rht]);
            if (*S.rbegin() - *S.begin() > limit) {
                S.erase(S.lower_bound(A[lft])); lft++;
            }
            ans = max(ans, rht - lft + 1);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestSubarray({8,2,4,7}, 4) << endl;
    cout << sol.longestSubarray({10,1,2,4,7,2}, 5) << endl;
    cout << sol.longestSubarray({4,2,2,2,4,4,2,2}, 0) << endl;
    return 0;
}
