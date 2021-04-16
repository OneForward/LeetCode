/*
leet665


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
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    bool checkPossibility(const vector<int>& nums) {
        // 看似简单，实则细节复杂
        // 可行的要求为 
        // a. 下降沿不超过 2
        // b. 对每一个下降沿 prev > x, 经过变换后 prevprev <= prev <= x <= next 可以成立
        //   P1 prevprev <= x 或者 prev <= next 成立
        //   P2 x 是最后一个数，则一定成立
        // b 这个条件可以描述为   P2 or P1
        int n = nums.size();
        if (n < 3) return true;
        int count = nums[0] <= nums[1] ? 0 : 1;
        for (int i = 2; i < n; ++i) {
            if (nums[i-1] > nums[i]) {
                count++;
                if (count > 1) return false;
                if (not
                    (i == n-1 
                    or nums[i-2] <= nums[i]  
                    or nums[i-1] <= nums[i+1]) 
                )
                    return false;
            }
        }
        return true;
    }
    bool checkPossibility2(vector<int>& nums) 
    {
        if (nums.size() == 1)   return true;
        int flag = nums[0] <= nums[1] ? true : false; // 标识是否还能修改
        // 遍历时，每次需要看连续的三个元素
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])  // 出现递减
            {
                if (flag)   // 如果还有修改机会，进行修改
                {
                    if (nums[i + 1] >= nums[ i - 1])// 修改方案1
                        nums[i] = nums[i + 1];
                    else                            // 修改方案2
                        nums[i + 1] = nums[i];      
                    flag = false;                   // 用掉唯一的修改机会
                }   
                else        // 没有修改机会，直接结束
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    cout << boolalpha;

    Solution sol;   
    cout << sol.checkPossibility({-1,4,2,3}) << endl;
    cout << sol.checkPossibility({3,4,2,3}) << endl;
    cout << sol.checkPossibility({5,7,1,8}) << endl;
    cout << sol.checkPossibility({4,2,3}) << endl;
    cout << sol.checkPossibility({4,2,1}) << endl;
    cout << sol.checkPossibility({1,3,2}) << endl;
    return 0;
}
