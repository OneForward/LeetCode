#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

class Solution {
public:
/*
    分治方法
*/

    int merge_sort(long* sums, int lo, int hi, const int& lower, const int& upper, int* tmp) {
        if (hi <= lo) return 0;
        int mid = (lo + hi) / 2;
        int cnt = merge_sort(sums, lo, mid, lower, upper, tmp) + merge_sort(sums, mid+1, hi, lower, upper, tmp);

        int rht1 = mid+1, rht2 = mid+1, k;
        for (int lft = lo; lft <= mid; ++lft) {
            while (rht1 <= hi and sums[rht1]-sums[lft] <  lower) ++rht1;
            while (rht2 <= hi and sums[rht2]-sums[lft] <= upper) ++rht2;
            cnt += rht2 - rht1;
        }

        rht1 = lo, rht2 = mid+1, k = lo;
        while (rht1 <= mid and rht2 <= hi) {
            while (rht1 <= mid and sums[rht1] <= sums[rht2]) tmp[k++] = sums[rht1++];
            while (rht2 <= hi and sums[rht1] > sums[rht2]) tmp[k++] = sums[rht2++];
        }
        while (rht1 <= mid) tmp[k++] = sums[rht1++];
        while (rht2 <= hi) tmp[k++] = sums[rht2++];
        for (int i=lo; i<=hi; ++i) sums[i] = tmp[i];
        return cnt;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        size_t size = nums.size();
        int* tmp = new int[size+1]();
        long* sums = new long[size+1]();
        for (int i=0; i<size; ++i)
            sums[i+1] = sums[i] + nums[i];
        int ans = merge_sort(sums, 0, size, lower, upper, tmp);
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    freopen("leet327/1.in", "r", stdin);

    int size;
    cin >> size;

    vector<int> nums(size);

    for (int i=0; i<size; ++i) cin >> nums[i];
    for (auto x: nums) printf("%d ", x); printf("\n");


    int lower, upper;
    cin >> lower >> upper;


    Solution solution;
    int ans = solution.countRangeSum(nums, lower, upper);
    printf("%d\n", ans);

    return 0;
        
}
