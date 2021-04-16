/*
leet1053


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
    vector<int> prevPermOpt1(vector<int> A) {
        // O(N)
        int n = A.size();
        int j = n - 1;
        while (j > 0 and A[j-1] <= A[j]) --j;
        if (j == 0) return A;

        auto i = n-1;
        while ( A[j-1] < A[i]) --i;
        swap(A[i], A[j-1]);

        // auto lft = j, rht = n-1;
        // while (lft < rht) swap(A[lft], A[rht]), lft++, rht--;
        return A;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.prevPermOpt1({3,2,1}) << endl;
    cout << sol.prevPermOpt1({1,1,5}) << endl;
    cout << sol.prevPermOpt1({1,9,4,6,7}) << endl;
    cout << sol.prevPermOpt1({3,1,1,3}) << endl;
    return 0;
}
