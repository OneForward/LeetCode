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
        // O(N log N) in Time, O(N) in space
        sort(A.begin(), A.end());
        
        int n = A.size(), R[] = {(n + 1) / 2 - 1, n - 1};
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
