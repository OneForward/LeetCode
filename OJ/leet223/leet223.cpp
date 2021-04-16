/*
leet223


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
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int dx = max( (long long)min(C, G) - max(A, E), (long long)0 );
        int dy = max( (long long)min(D, H) - max(B, F), (long long)0 );
        return (long long)(D - B) * (C - A)  -  dx * dy + (H - F) * (G - E);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}
