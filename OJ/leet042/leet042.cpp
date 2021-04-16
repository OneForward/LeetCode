/*
leet042


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;



class Solution {
public:

    int trap(vector<int>&& v) {
        // 4ms, 左右扫描+双指针方法, 时间O(N), 空间O(1)
        size_t n = v.size();
        int lft_max = 0, rht_max = 0;

        int S = 0; int lft = 0, rht = n-1;
        while (lft < rht) {
            if (v[lft] > lft_max) lft_max = v[lft];
            if (v[rht] > rht_max) rht_max = v[rht];
            if (lft_max < rht_max) {
                S += lft_max - v[lft]; lft++;
            }
            else {
                S += rht_max - v[rht]; rht--;
            }
        } 
        return S;
    }

    int trap2(vector<int>&& v) {
        // 4ms, 左右扫描, 时间O(N), 空间O(N)
        size_t n = v.size();
        vector<int> lft(n) , rht(n);
        int lft_max = 0, rht_max = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] > lft_max) lft_max = v[i];
            lft[i] = lft_max;
        }
        for (int i = n-1; i >= 0; --i) {
            if (v[i] > rht_max) rht_max = v[i];
            rht[i] = rht_max;
        }

        int S = 0;
        for (int i = 0; i < n; ++i) {
            S += min(lft[i], rht[i]) - v[i];
        } 
        return S;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.trap({0,1,0,2,1,0,1,3,2,1,2,1}) << endl;
    cout << sol.trap({5,5,1,7,1,1,5,2,7,6}) << endl;
    cout << sol.trap({2,8,5,5,6,1,7,4,5}) << endl;
    cout << sol.trap({5, 2, 1, 2, 1, 5}) << endl;

    return 0;
}
