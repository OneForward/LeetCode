/*
leet096


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // 0ms
        vector<int> v(n+1, 0);
        v[0] = v[1] = 1;
        for (int m = 2; m <= n; ++m) {
            for (int i = 0; i < m; ++i) {
                v[m] += v[i] * v[m-1-i];
            }
        }
        return v[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    for (auto n: {1, 2, 3 ,4 , 5, 6})
        cout << "n = " << n << " : " << sol.numTrees(n) << endl;
    return 0;
}
