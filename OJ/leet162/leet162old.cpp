/*
leet162


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
    int findPeakElement1(const vector<int>& nums) {
        // 8ms, O(N)
        int i = 1, n = nums.size();
        while (i < n && nums[i] > nums[i-1]) ++i;
        return i-1;
    }

    int findPeakElement(const vector<int>& nums) {
        // 12ms, O(log N)
        size_t lft = 0, rht = nums.size()-1, mid;
        while (lft < rht) {
            mid = ((lft + rht) >> 1);
            if (nums[mid] > nums[mid+1]) rht = mid;
            else lft = mid+1;
        }
        return lft;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findPeakElement({1,2,1,3,5,6,4}) << endl;
    return 0;
}
