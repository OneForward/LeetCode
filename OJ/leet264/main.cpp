#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int check235(int n) {
    if (n % 5 == 0) return n / 5;
    if (n % 3 == 0) return n / 3;
    if (n % 2 == 0) return n / 2;
    return -1;
}

bool isUgly(int n) {
    while  (n > 1) {
        n = check235(n);
    }
    if (n == 1) return true;
    else return false;
}

/*
三指针
*/


#define INF 0xFFFFFFFF
#define min(x, y) (((x) < (y)) ? (x) : (y))

class Solution1 {
public:
    size_t nthUglyNumber(size_t n) {
        size_t* A = new size_t[n+1]; A[1] = 1;
        unordered_set<size_t> L2, L3, L5;
        L2.insert(1); L3.insert(1); L5.insert(1);

        size_t minL2, minL3, minL5, val;
        unordered_set<size_t>::iterator it;
        for (size_t i=1; i<n; ++i) {
            minL2 = minL3 = minL5 = INF;
            for (it = L2.begin(); it != L2.end(); ++it) {val = (*it) * 2; if (val > A[i] and minL2 > val) minL2 = val;}
            for (it = L3.begin(); it != L3.end(); ++it) {val = (*it) * 3; if (val > A[i] and minL3 > val) minL3 = val;}
            for (it = L5.begin(); it != L5.end(); ++it) {val = (*it) * 5; if (val > A[i] and minL5 > val) minL5 = val;}
            val = min( min( minL2, minL3), minL5 );
            L2.insert(val); L3.insert(val); L5.insert(val);
            it = L2.find(val / 2); if (it != L2.end()) L2.erase(it);
            it = L3.find(val / 3); if (it != L3.end()) L3.erase(it);
            it = L5.find(val / 5); if (it != L5.end()) L5.erase(it);
            A[i+1] = val;
        }
        for (int i=1; i<=n; ++i) printf("%11u,", A[i]);
        return A[n];
    }
};

class Solution {
public:
    size_t nthUglyNumber(size_t n) {
        vector<size_t> A(n);
        A[0] = 1;
        size_t i2(0), i3(0), i5(0);
        for (size_t i=1; i<n; ++i) {
            A[i] = min( min( A[i2]*2, A[i3]*3 ), A[i5]*5 );
            if (A[i2]*2 == A[i]) i2++;
            if (A[i3]*3 == A[i]) i3++;
            if (A[i5]*5 == A[i]) i5++;
        }
        // for (size_t i=0; i<n; ++i) printf("%11u,", A[i]);
        return A[n-1];
    }
};

int main(int argc, char **argv)
{
    int n = 1690;
    Solution sol;

    sol.nthUglyNumber(n);
    printf("%u\n", sol.nthUglyNumber(n));
    // cout << sol.nthUglyNumber(n);
	return 0;
}
