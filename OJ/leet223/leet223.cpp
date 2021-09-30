/*
leet223


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int dx = max( min(C, G) - max(A, E), 0 );
        int dy = max( min(D, H) - max(B, F), 0 );
        return (long long)(D - B) * (C - A)  -  dx * dy + (H - F) * (G - E);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}
