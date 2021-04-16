/*
leet041

inplace hashing
*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> A) {
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            while (true) {
                auto x = A[i]; // x should be put in pos x-1
                if (x != i + 1 and 1 <= x and x <= n and A[x-1] != x) swap(A[x-1], A[i]);
                else break;
            }
        }
        for (int i = 0; i < n; ++i) if (A[i] != i + 1) return i + 1;
        return n + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.firstMissingPositive({1,2,0}) << endl;
    cout << sol.firstMissingPositive({3,4,-1,1}) << endl;

    return 0;
}
