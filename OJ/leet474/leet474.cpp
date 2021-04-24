/*
leet474


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
    int findMaxForm(const vector<string>& S, int M, int N) {
        // 0-1 pack

        int f[101][101]{};
        for (auto&& s: S) {
            int zero = count(s.begin(), s.end(), '0'), one = s.size() - zero;
            for (int m = M; m >= zero; --m) {
                for (int n = N; n >= one; --n) {
                    f[m][n] = max(f[m][n], f[m-zero][n-one] + 1);
                }
            }
        }
        return f[M][N];

    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findMaxForm({"10", "0001", "111001", "1", "0"}, 5, 3) << endl;
    cout << sol.findMaxForm({"10", "0", "1"}, 1, 1) << endl;

    return 0;
}
