/*
leet523


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
    bool checkSubarraySum(vector<int>& A, int k) {
        unordered_map<int, int> M;
        auto sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            sum += A[i];
            if (k) sum %= k;
            if (sum == 0 and i > 1) return true;
            if (M.find(sum) == M.end() ) M[sum] = i;
            else if (i - M[sum] > 1) return true;
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
