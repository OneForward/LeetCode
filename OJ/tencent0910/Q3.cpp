/*
tencent0910


*/

// #include "../utils/LeetCpp.utils.hpp"
#include <iostream>
#include <vector>

using namespace std;

// #define ALL(A) A.begin(),A.end()
// using VI=vector<int>;
// using VVI=vector<VI>;


int reversePairs(vector<int>& A) {
    int n =  A.size();
    vector<int> B(n);

    int cnt = 0;
    auto merge = [&](int l1, int r1, int l2, int r2) {
        int p1 = l1, p2 = l2, p = l1;
        while (p1 < r1 and p2 < r2) {
            if (A[p1] <= A[p2]) B[p++] = A[p1++];
            else  B[p++] = A[p2++], cnt += r1 - p1;
        }
        while (p1 < r1) B[p++] = A[p1++];
        while (p2 < r2) B[p++] = A[p2++];
        for (p = l1; p < r2; ++p)  A[p] = B[p];
    };

    for (int len = 1; len < n; len *= 2) {
        for (int i = 0; i + len < n; i += 2 * len) {
            merge(i, i+len, i+len, min(i+2*len, n));
        }
    }
    return cnt;
}


int main()
{   
    auto v = vector{2,6,8,9,4,1};
    cout << reversePairs( v ) << endl;
    return 0;
}
