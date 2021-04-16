/*
leet896


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
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {

public:
    bool isMonotonic(const vector<int>& A) {
        int ans = 0;
        for (size_t i = 0; i < A.size()-1; i++)
        {
            if (A[i] < A[i+1]) ans |= 1;
            if (A[i] > A[i+1]) ans |= 2;
            if (ans == 3) return false;
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   

    return 0;
}
