/*
leet413


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
        int n = A.size();
        vector<int> f(n);
        for (int i = 2; i < n; ++i) { 
            if (A[i-1] * 2 == A[i-2] + A[i]) f[i] = f[i-1] + 1;
        }
        return accumulate(f.begin(), f.end(), 0);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.numberOfArithmeticSlices( {1,2,3,4} ) << endl;
    return 0;
}
