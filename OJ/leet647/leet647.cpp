/*
leet647


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // O(n), O(n), Manacher 算法, 0ms
        // 另一种解法是中心扩散方法，O(n^2), O(1), 朴素搜索即可
        vector<char> v = {'$', '.'};
        for (const auto& ch: s) {
            v.push_back(ch); v.push_back('.');
        }
        v.push_back('%');
        string snew = string(v.begin(), v.end());

        int n = snew.size();
        vector<int> p(n); // 臂长
        int C = 0, R = 0;
        int ans = 0;
        for (int i = 2; i < n-1; ++i) {
            if (i < R) {
                p[i] = min( R-i, p[2*C-i] );
            }
            while ( snew[i-p[i]-1] ==  snew[i+p[i]+1] ) p[i]++;
            if (i + p[i] > R) {
                R = i + p[i];
                C = i;
            }
            ans += ( p[i] + 1 ) /  2;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.countSubstrings("aaa") << endl;
    cout << sol.countSubstrings("abc") << endl;
    cout << sol.countSubstrings("babad") << endl;
    return 0;
}
