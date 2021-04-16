/*
leet189


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

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}
class Solution {
public:
    void rotate1(vector<int>& nums, int k) {
        // 旋转k次
        int n = nums.size(); k %= n;
        auto one_move = [&] () {
            int t = nums[n-1];
            for (int i = n-1; i > 0; --i) nums[i] = nums[i-1];
            nums[0] = t;
        };
        while (k--) one_move();
    }
    void rotate2(vector<int>& nums, int k) {
        // 12ms, 直接逐项旋转到第k位
        int n = nums.size(), imax = gcd(n, k); k %= n; 
        for (int i=0; i<imax; ++i) {
            int st = (i+n-k)%n, t = nums[ st ], prev;
            while (st != i) prev = (st+n-k)%n, nums[st] = nums[ prev ], st = prev;
            nums[i] = t;
        }
    }
    void rotate(vector<int>& nums, int k) {
        // 12ms, 反转, 再对前k个和后(n-k)个分别反转
        int n = nums.size(); k %= n;

        auto reverse = [&] (int lft, int rht) {
            for (int i=lft; i<(lft+rht)/2; ++i) swap(nums[i], nums[rht+lft-1-i]);
        };
        
        reverse(0, n);
        reverse(0, k);
        reverse(k, n);
    }
};


int main(int argc, char const *argv[])
{
    // vector v = {1,2,3,4,5,6,7}; int k = 3;
    // vector v = {1,2,3,4,5,6,7,8,9,10,11,12}; int k = 3;
    vector v = {1,2,3,4,5,6,7}; int k = 3;
    Solution sol;   
    sol.rotate(v, k);
    for (auto vi: v) cout << vi << ", ";
    return 0;
}
