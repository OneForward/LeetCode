/*
leet088


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 4ms
        int p1 = m-1, p2 = n-1, cur = m + n - 1;
        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) nums1[cur--] = nums1[p1--];
            else nums1[cur--] = nums2[p2--];
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    vector v1 = {1, 2, 3, 0, 0, 0}, v2 = {2, 5, 6};
    int m = 3, n = 3;
    sol.merge(v1, m, v2, n);
    for (auto vi: v1) cout << vi << ", "; cout << endl;
    return 0;
}
