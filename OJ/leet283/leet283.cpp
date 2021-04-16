/*
leet283


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Time O(N), Space O(1)
        int lft = 0, rht = 0, n = nums.size();
        while (lft < n && nums[lft] != 0) lft++;
        rht = lft + 1;
        while (rht < n) {
            // if (nums[rht] != 0) nums[lft++] = nums[rht++];
            // else rht++;
            if (nums[rht] != 0) swap(nums[lft++], nums[rht++]);
            else rht++;
        }
        // while (lft < n) nums[lft++] = 0;
    }
};

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}

int main(int argc, char const *argv[])
{
    Solution sol;  
    
    vector<int> v = {0,1,0,3,12}; sol.moveZeroes(v); cout << v;
    return 0;
}
