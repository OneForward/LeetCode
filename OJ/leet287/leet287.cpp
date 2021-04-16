/*
leet287


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
    int findDuplicate(const vector<int>& A) {
        // Floyd, O(N), 不修改 A
        auto slow = 0, fast = 0;
        while (true) {
            slow = A[slow];
            fast = A[A[fast]];
            if (slow == fast) break;
        }

        auto C = 0;
        while (C != slow) {
            C = A[C]; slow = A[slow];
        }
        return C;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findDuplicate({1,3,4,2,2}) << endl;
    cout << sol.findDuplicate({3,1,3,4,2}) << endl;
    cout << sol.findDuplicate({1, 1}) << endl;
    cout << sol.findDuplicate({2,5,9,6,9,3,8,9,7,1}) << endl;
    return 0;
}
