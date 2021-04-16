/*
leet238


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


class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        // Time O(N),  Space O(1) extra
        vector<int> v(nums.size()); v[0] = 1;
        int n = nums.size();
        for (int i = 0; i < n-1; ++i) { 
            v[i+1] = v[i] * nums[i];
        }    
        int tmp = 1;
        for (int i = n-1; i >= 0; --i) { 
            v[i] *= tmp; tmp *= nums[i];
        }    
        return v;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.productExceptSelf({1,2,3,4}) ;
    cout << sol.productExceptSelf({1,2,0,4}) ;
    return 0;
}
