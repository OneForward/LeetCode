/*
leet164


*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

struct Bucket {
    bool used = false;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    void update(int x) {
        used = true;
        minVal = min(minVal, x), maxVal = max(maxVal, x);
    }
};


class Solution {
public:
    int maximumGap(const vector<int>& v) {
        // 4ms, 桶排序, 鸽笼原理, O(N + B) 
        if (v.size() < 2) return 0;

        int minVal = INT_MAX, maxVal = INT_MIN, n = v.size(); 
        for (auto x: v) minVal = min(minVal, x), maxVal = max(maxVal, x);
        int b = max(1, (maxVal - minVal) / (n - 1)) , k = (maxVal - minVal) / b + 1;
        Bucket* Bs = new Bucket[k];
        for (auto x: v) {
            int pos = (x - minVal) / b;
            Bs[pos].update(x);
        }

        int ans = 0, prev = 0;
        for (int i = 1; i < k; ++i) {
            if (Bs[i].used) {
                ans = max(Bs[i].minVal - Bs[prev].maxVal, ans);
                prev = i;
            }
        }
        return ans;
    }

    int maximumGap1(vector<int>& v) {
        // 20ms, qsort, O(N log N)
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 1; i < v.size(); ++i) {
            ans = max(v[i]-v[i-1], ans);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    vector v = {3,6,9,1};
    Solution sol;   
    cout << sol.maximumGap(v) << endl;
    cout << sol.maximumGap({}) << endl;
    cout << sol.maximumGap({1,1,1}) << endl;

    return 0;
}
