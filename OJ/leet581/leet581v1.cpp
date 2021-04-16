/*
leet581


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(const vector<int>& A) {
        int n = A.size(), lft = n, rht = 0;
        int maxVal = A[0], minVal = A[n-1];
        for (int i = 0; i < n; ++i) {
            if (maxVal > A[i]) rht = i;
            else maxVal = A[i];
        }
        for (int i = n-1; i >= 0; --i) {
            if (minVal < A[i]) lft = i;
            else minVal = A[i];
        }
        return max(rht - lft + 1, 0);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findUnsortedSubarray({1,3,2,2,2}) << endl;
    cout << sol.findUnsortedSubarray({2,6,4,8,10,9,15}) << endl;
    cout << sol.findUnsortedSubarray({1,2,3,4}) << endl;
    cout << sol.findUnsortedSubarray({1}) << endl;
    cout << sol.findUnsortedSubarray({1,1}) << endl;
    return 0;
}
