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
        // O(N log N)
        int n = A.size();
        map<int, int, greater<int>> tree;
        vector<int> f(n);
        for (int i = n-1; i >= 0; i--)
        {
            auto pos = tree.upper_bound(A[i]);
            if (pos == tree.end()) f[i] = -1;
            else f[i] = pos->second;
            tree[A[i]] = i;
        }
        
        for (int i = n - 2; i >= 0; i--)
        {
            if (f[i] != -1) {
                swap(A[f[i]], A[i]);
                break;
            }
        }
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
