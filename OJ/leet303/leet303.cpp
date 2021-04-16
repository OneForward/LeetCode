/*
leet303


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

class NumArray {
public:
    vector<int> sum;
    NumArray(const vector<int>& nums) {
        int n = nums.size();
        sum.resize(n+1); sum[0] = 0;
        for (int i = 0; i < n; ++i) { 
            sum[i+1] = sum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
};


int main(int argc, char const *argv[])
{
    NumArray numArray({-2, 0, 3, -5, 2, -1}) ;
    cout << endl << numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
    cout << endl << numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
    cout << endl << numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
    
    return 0;
}
