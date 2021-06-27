/*
leet004


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) { 
        auto m = A.size(), n = B.size();
        auto K1 = (m + n + 1) / 2, K2 = (m + n + 2) / 2;
        return ( getKth(A, B, 0, m, 0, n, K1) +  getKth(A, B, 0, m, 0, n, K2) ) / 2.;
    }

    double getKth(const vector<int>& A, const vector<int>& B, int l1, int r1, int l2, int r2, int K) {
        int len1 = r1 - l1;
        int len2 = r2 - l2;
        if (len1 > len2) return getKth(B, A, l2, r2, l1, r1, K);
        if (len1 == 0) return B[l2+K-1];

        if (K == 1) return min(A[l1], B[l2]);

        int x = l1 + min(len1, K / 2) - 1;
        int y = l2 + min(len2, K / 2) - 1;

        if (A[x] > B[y]) return getKth(A, B, l1, r1, y+1, r2, K - (y - l2 + 1));
        else return getKth(A, B, x + 1, r1, l2, r2, K - (x - l1 + 1));
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findMedianSortedArrays( {1, 3}, {2} ) << endl;
    cout << sol.findMedianSortedArrays( {1, 2}, {3,4} ) << endl;
    cout << sol.findMedianSortedArrays( {0, 0}, {0, 0} ) << endl;
    return 0;
}
