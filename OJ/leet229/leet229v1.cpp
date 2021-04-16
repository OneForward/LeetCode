/*
leet229


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

class Solution {
public:
    vector<int> majorityElement(const vector<int>& nums) {
        // 24ms, 摩尔投票法，挑选频数超过 floor(n/2) 的众数, O(N), O(1)
        if (nums.empty()) return {};
        int cand1 = nums[0], cnt1 = 0, cand2 = nums[0], cnt2 = 0;
        int p = 0;
        while (p < nums.size()) {
            if (nums[p] == cand1) cnt1++;
            else if (nums[p] == cand2) cnt2++;
            else {
                if (cnt1 == 0) cand1 = nums[p], cnt1 = 1;
                else if (cnt2 == 0) cand2 = nums[p], cnt2 = 1;
                else cnt1--, cnt2--;
            }
            ++p;
        }
        cnt1 = cnt2 = 0;
        for (auto x: nums) {
            if (x == cand1) cnt1++;
            else if (x == cand2) cnt2++;
        }
        vector<int> ans;
        if (cnt1 > nums.size()/3) ans.push_back(cand1);
        if (cnt2 > nums.size()/3) ans.push_back(cand2);
        return ans;
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
    cout << sol.majorityElement( {1,1,1,3,3,2,2,2} ); 
    cout << sol.majorityElement( {3,2,3} ); 

    vector<vector<int>> v = {{1,2,3}, {2,3,4}};
    cout << v;
    return 0;
}
