/*
leet324


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> A) {
        int n = A.size(), R[] = {(n + 1) / 2 - 1, n - 1};

        // Find a median.
        nth_element(A.begin(), A.begin() + n / 2, A.end());
        auto mid = A[n / 2];

        // 3-way-partition
        // A[0:i) < mid; A[i:j) == mid;  A[k:] > mid
        auto i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A[j] < mid) swap(A[j++], A[i++]);
            else if (A[j] > mid) swap(A[j], A[k--]);
            else j++;
        }


        auto B = A;
        for (int i = 0; i < n; ++i) B[i] = A[R[i % 2]--];
        A = B;
        cout << A << endl;
    }
};
 


int main(int argc, char const *argv[])
{
    Solution sol;   
    sol.wiggleSort({1,5,1,1,6,4});
    sol.wiggleSort({1,3,2,2,3,1});
    return 0;
}
