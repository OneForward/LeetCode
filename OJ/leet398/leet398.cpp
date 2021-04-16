/*
leet398


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
    vector<int> A;
    mt19937 gen; //Standard mersenne_twister_engine seeded with rd()
    
    Solution(const vector<int>& nums): A{nums}, gen{} { }
    
    int pick(int target) {
        int K = 1, ans = 0;
        
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == target)  {
                uniform_int_distribution<> distrib(1, K);
                auto x = distrib(gen);
                if (K == 1 or x == 1) ans = i;
                K++;
            }
        }
        return ans;
    }
};



int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,3,3};
    Solution solution = Solution(nums);

    // pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
    cout << endl << solution.pick(3);

    // pick(1) 应该返回 0。因为只有nums[0]等于1。
    cout << endl << solution.pick(1); 
    return 0;
}
