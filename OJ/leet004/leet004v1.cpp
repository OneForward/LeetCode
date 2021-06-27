/*
leet004


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
        // O(log min(m, n))
        // A[0..x) 我们希望 A[x] 恰好满足：B[y-1] <= A[x] <= B[y] 且 x + y == half 
        // B[0..y) 则 A 提供了 x 个数 (0 .. m), B 提供了 y 个数
        const int m = A.size(), n = B.size(), K = (m + n) / 2;
        if (m > n) return findMedianSortedArrays(B, A);
        if (m == 0) 
            return n % 2 == 0 ? (B[K-1] + B[K]) / 2. : B[K];

        int lft = 0, rht = A.size() + 1, x, y;
        while (lft < rht) {
            x = (lft + rht) / 2;
            y = K - x;
            if (x == 0) {
                if ( A[x] < B[y-1] ) lft = x + 1;
                else break;
            }
            else if (x == m) {
                if ( B[y] < A[x-1] ) rht = x;
                else break;
            }
            else {
                if ( A[x] < B[y-1] ) lft = x + 1;
                else if ( B[y] < A[x-1] ) rht = x;
                else break;
            }
        }

        if ((m + n) % 2) { // odd
            if (x == m) return B[y];
            return min(A[x], B[y]);
        }

        // even
        int mlft, mrht;
        if (x == 0) mlft = B[y-1], mrht = y == n ? A[0] : min(A[0], B[y]);
        else if (x == m) mlft = y == 0 ? A[x-1] : max(A[x-1], B[y-1]), mrht = B[y];
        else mlft = max(A[x-1], B[y-1]), mrht = min(A[x], B[y]);
        return (mlft + mrht) / 2.;
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
