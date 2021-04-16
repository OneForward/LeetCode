/*
leet1409


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



struct BIT // 树状数组
{
    vector<int> L;
    int n;

    inline int lowbit(int x) {  return x & -x; }
    
    BIT(int _n): n{_n}, L(_n) {}

    int query(int i) { // 返回 [1, i] 的区间和
        int ans = 0;
        while (i) ans += L[i], i -= lowbit(i);
        return ans;
    }

    void update(int i, int x) { // A[i] += x
        while (i < n) L[i] += x, i += lowbit(i);
    }

};


class Solution {
public:
    vector<int> processQueries(const vector<int>& queries, int m) {
        // O(M + Qlog(M+Q)), 树状数组
        int n = queries.size();
        BIT tree(n + m + 1);
        vector<int> pos(m + 1);
        
        // 建树
        for (int i = n + 1; i <= n + m; i++) 
            tree.update(i, 1);

        for (int i = 1; i <= m; i++)
            pos[i] = n + i;
        
            
        vector<int> ans; ans.reserve(n); 
        for (int i = 0; i < n; ++i) {
            auto x = queries[i];

            tree.update(pos[x], -1);
            
            ans.push_back(tree.query(pos[x]));

            pos[x] = n - i;
            tree.update(pos[x], 1);
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.processQueries({3,1,2,1}, 5) << endl;
    cout << sol.processQueries({4,1,2,2}, 4) << endl;
    cout << sol.processQueries({7,5,5,8,3}, 8) << endl;
    return 0;
}
