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

    int merge_sort(vector<int>& nums, int lo, int hi, int* tmp) {
        if (hi <= lo) return 0;
        int mid = (lo + hi) / 2;
        int cnt = merge_sort(nums, lo, mid, tmp) + merge_sort(nums, mid+1, hi,  tmp);

        int rht = mid+1;
        for (int lft = lo; lft <= mid; ++lft) {
            while (rht <= hi and nums[lft] > (long)2*nums[rht]) ++rht;
            cnt += rht - mid - 1;
        }

        int rht1 = lo, rht2 = mid+1, k = lo;
        while (rht1 <= mid and rht2 <= hi) {
            while (rht1 <= mid and nums[rht1] <= nums[rht2]) tmp[k++] = nums[rht1++];
            while (rht2 <= hi and nums[rht1] > nums[rht2]) tmp[k++] = nums[rht2++];
        }
        while (rht1 <= mid) tmp[k++] = nums[rht1++];
        while (rht2 <= hi) tmp[k++] = nums[rht2++];
        for (int i=lo; i<=hi; ++i) nums[i] = tmp[i];
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        size_t size = nums.size();
        int* tmp = new int[size+1]();
        int ans = merge_sort(nums, 0, size-1, tmp);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    // freopen("leet493/2.in", "r", stdin);

    int size;
    cin >> size;

    vector<int> nums(size);

    for (int i=0; i<size; ++i) cin >> nums[i];
    for (auto x: nums) printf("%d ", x); printf("\n");


    Solution solution;
    int ans = solution.reversePairs(nums);
    printf("%d\n", ans);

    return 0;
        
}
