/*
leet169


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;



class Solution {
public:
    int majorityElement(const vector<int>& nums) {
        // 摩尔投票法, O(N), O(1)
        int can = nums[0], cnt = 0;
        for (auto x: nums) {
            if (can == x) cnt++;
            else {
                if (cnt == 0) can = x, cnt = 1;
                else cnt--;
            }
        }
        return can;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.majorityElement( {3,2,3} ) << endl;
    cout << sol.majorityElement( {2,2,1,1,1,2,2} ) << endl;
    return 0;
}
