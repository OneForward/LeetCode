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
        int j = n - 2;
        while (j >= 0 and A[j] <= A[j+1]) --j;
        if (j == -1) return A;

        int pos = j+1;
        for (size_t i = j+1; i < n; i++)
        {
            if (A[j] > A[i] and A[i] > A[pos]) pos = i;
        }
        
        swap(A[pos], A[j]);

        return A;
    }
};

class Solution2 {
public:
    vector<int> prevPermOpt1(vector<int> A) {
        // O(N)
        int n = A.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (A[i+1] < A[i]) {
                auto pos = i;
                for (size_t j = i+1; j < n; j++) {
                    if (A[i] > A[j] and A[j] > A[pos]) {
                        pos = j;
                    }
                }
                swap(A[i], A[pos]);
                return A;
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
