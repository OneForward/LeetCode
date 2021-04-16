/*
leet229


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
    vector<int> majorityElement(const vector<int>& nums) {
        int n = nums.size();
        auto A = nums[0], B = nums[0];
        auto cntA = 0, cntB = 0;
        for (auto&& x: nums) {
            if (x == A) cntA++;
            else if (x == B) cntB++;
            else {
                if (cntA == 0) A = x, cntA = 1;
                else if (cntB == 0) B = x, cntB = 1;
                else cntA--, cntB--;
            }
        }
        
        cntA = 0, cntB = 0;
        for (auto&& x: nums) {
            if (x == A) cntA++;
            else if (x == B) cntB++;
        }
        
        vector<int> ans;
        if (cntA > n / 3) ans.push_back(A);
        if (cntB > n / 3) ans.push_back(B);
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.majorityElement( {1,1,2,3,4} ) << endl;
    return 0;
}
