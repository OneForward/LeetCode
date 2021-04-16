/*
leet128

并查集
*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        // O(N), 并查集
        // 每棵并查集树代表一个连续数列
        // M[x] 保存的是 x 的父节点，也就是并查集的根, 也就是数列最小值
        // M[root] 保存数列最大值
        if (nums.empty()) return 0;
        unordered_map<int, int> M; int ans = 0, root;
        for (const auto& x: nums) {
            auto p = M.find(x);
            if (p != M.end()) continue;

            M[x] = x;
            p = M.find(x - 1);
            if (p != M.end()) M[x] = M[x-1], M[M[x-1]] = x, ans = max(ans, x - M[x]);
            p = M.find(x + 1);
            if (p != M.end()) ans = max(ans, M[x+1]-M[x]), root = M[x], M[root] = M[x+1], M[M[x+1]] = root;
        }
        return ans + 1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestConsecutive({ 100, 4, 200, 1, 3, 2 }) << endl;
    cout << sol.longestConsecutive({0,3,7,2,5,8,4,6,0,1}) << endl;
    return 0;
}
