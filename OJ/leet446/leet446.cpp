/*
leet446


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
#include <numeric>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(const vector<int>& A) {
        // f[i][d] 代表 以 A[i] 结尾的等差数列且公差为 d 的弱等差数列的数目
        // 1296ms, 弱等差数列： 两个数也算等差数列
        int n = A.size();
        vector<unordered_map<long long, int>> f(n);
        
        int ans = 0;
        for (int i = 1; i < n; ++i) { 
            for (int j = 0; j < i; ++j) { 
                auto d = (long long)A[i] - A[j];
                auto p = f[j].find( d );
                if (p != f[j].end()) {
                    f[i][d] += f[j][d];
                    ans += f[j][d];
                }
                f[i][d]++;
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.numberOfArithmeticSlices( {1,2,3,4} ) << endl;
    cout << sol.numberOfArithmeticSlices( {2,2,3,4} ) << endl;
    cout << sol.numberOfArithmeticSlices( {2, 4, 6, 8, 10} ) << endl;
    return 0;
}
