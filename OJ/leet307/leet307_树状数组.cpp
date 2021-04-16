#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

inline int lowbit(int x) { return x & -x; }

// 树状数组

class NumArray {
public:
    int N;
    vector<int> tree;
    vector<int> A;
    NumArray(const vector<int>& nums) {
        N = nums.size(); A = nums;
        tree.resize(N+1);
        for (int i = 1; i <= N; ++i) tree[i] = nums[i-1];
        for (int i = 1; i <= N; ++i) {
            int j = i + lowbit(i);
            if (j <= N) tree[j] += tree[i];
        }
    }
    
    void update(int index, int val) {
        // A[index]
        auto diff = val - A[index]; A[index] = val;
        index++; 
        while (index <= N) {
            tree[index] += diff;
            index += lowbit(index);
        }
    }
    
    int prefix(int index) {
        // sum A[1,index]
        int ans = 0; 
        while (index >= 1) {
            ans += tree[index];
            index -= lowbit(index);
        }
        return ans;
    }
    int sumRange(int left, int right) {
        return prefix(right+1) - prefix(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(int argc, char const *argv[])
{
    freopen("1.in", "r", stdin);

    int size, K, lft, rht, type, ans;
    cin >> size;
    vector<int> nums(size, 0);
    for (int i=0; i<size; ++i) cin >> nums[i];
    
    // for (auto x: nums) printf("%d ", x);
    NumArray* obj = new NumArray(nums);
    cin >> K;
    while (K--) {
       scanf("%d %d %d", &type, &lft, &rht);
       // printf("%d %d %d\n", type, lft, rht);
       switch (type) {
           case 0: ans = obj->sumRange(lft,rht); printf("%d\n", ans); break;
           case 1: obj->update(lft, rht);
       }
    }

    // cout << ans;


    return 0;
        
}

// int main(int argc, char const *argv[])
// {
//     NumArray numArray({1,3,5});
//     cout << numArray.sumRange(0, 2) << endl; // 返回 9 ，sum([1,3,5]) = 9
//     numArray.update(1, 2);   // nums = [1,2,5]
//     cout << numArray.sumRange(0, 2) << endl; // 返回 8 ，sum([1,2,5]) = 9
//     return 0;
        
// }
