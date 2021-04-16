#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> index(1005, -1);
        vector<int> cnt(arr2.size(), 0), rest;
        vector<int> ans(arr1.size(), 0);

        for (int i=0; i<arr2.size(); ++i) index[arr2[i]] = i;
        // printf("\n arr1: "); for (auto x: arr1) printf("%d, ", x);
        // printf("\n index: "); for (auto x: index) printf("%3d, ", x);

        for (auto ai:arr1) {
            if (index[ai] == -1) {
                rest.push_back(ai);
            }
            else {
                cnt[index[ai]] += 1;
            }
        }

        sort(rest.begin(), rest.end());
        // printf("\n cnt:   "); for (auto x: cnt) printf("%3d, ", x);
        // printf("\n rest:   "); for (auto x: rest) printf("%3d, ", x);
        // printf("\n");

        int start = 0;
        for (int i=0; i<cnt.size(); ++i)  {
            int ci = cnt[i];
            while (ci--) ans[start++] = arr2[i];
        }
        for (auto ri: rest) {
            ans[start++] = ri;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19},  
                arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> ans = sol.relativeSortArray(arr1, arr2);
    for (auto ai: ans) printf("%d, ", ai);
    return 0;
}
