/*
leet201


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd0(int m, int n) {
        int x = m;
        for (int i = m; i <= n; ++i) x &= i;
        return x;
    }
    int rangeBitwiseAnd1(int m, int n) {
        int cnt = 30, ans = 1 << cnt;
        while ( (ans & n) == 0 && cnt >= 1) ans >>= 1, cnt--;
        if ((ans & m) == 0) return 0;
        while ( (ans & m) == (ans & n) && cnt >= 1 ) ans >>= 1, cnt--;
        ans = m & n;
        for (int i = 0; i < cnt; ++i) ans >>= 1;
        return ans << cnt;
    }

    int rangeBitwiseAnd2(int m, int n) {
        int shift = 0;
        while (m < n) {
            m >>= 1; n >>= 1; shift++;
        }
        return m << shift;
    }   
 
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            n &= (n-1);
        }
        return n;
    }   
};


int main(int argc, char const *argv[])
{
    Solution sol;   int m, n;
    m = 5, n = 7; cout << sol.rangeBitwiseAnd(m, n) << ", true value is " << sol.rangeBitwiseAnd0(m, n) << endl;
    m = 1, n = 7; cout << sol.rangeBitwiseAnd(m, n) << ", true value is " << sol.rangeBitwiseAnd0(m, n) << endl;
    m = 34, n = 40; cout << sol.rangeBitwiseAnd(m, n) << ", true value is " << sol.rangeBitwiseAnd0(m, n) << endl;
    m = 0, n = 0; cout << sol.rangeBitwiseAnd(m, n) << ", true value is " << sol.rangeBitwiseAnd0(m, n) << endl;
    m = 7, n = 7; cout << sol.rangeBitwiseAnd(m, n) << ", true value is " << sol.rangeBitwiseAnd0(m, n) << endl;
    return 0;
}
