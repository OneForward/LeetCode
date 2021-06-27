/*
leet1755


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution1 {
public:
    vector<int> powerset(const vector<int>& A, int start) {
        if (start == A.size()) return {0};

        auto no = powerset(A, start+1);
        auto yes = no; auto x = A[start];
        for (auto& yi: yes) yi += x;
        yes.insert(yes.end(), no.begin(), no.end());
        return yes;
    }
    int minAbsDifference(const vector<int>& A, int goal) {
        // O(N 2^N)
        auto sum = powerset(A, 0);
        int ans = INT_MAX;
        for (const auto& si: sum) ans = min(abs(si-goal), ans);
        return ans;
    }
};

class Solution {
public:
    vector<int> powerset(const vector<int>& A, int start) {
        if (start == A.size()) return {0};

        auto no = powerset(A, start+1);
        auto yes = no; auto x = A[start];
        for (auto& yi: yes) yi += x;
        yes.insert(yes.end(), no.begin(), no.end());
        return yes;
    }
    int minAbsDifference(const vector<int>& A, int goal) {
        // O(N 2^{N/2})  meet in the middle + 双指针
        // 对排序好的数组寻找最接近目标值的两个数
        
        int N = A.size();
        vector<int> A1(A.begin(), A.begin()+N/2);
        vector<int> A2(A.begin()+N/2, A.end());
        auto sum1 = powerset(A1, 0);
        auto sum2 = powerset(A2, 0);
        sort(sum1.begin(), sum1.end());
        sort(sum2.begin(), sum2.end(), greater<int>{});

        int ans = INT_MAX;
        for (const auto& x: sum1) ans = min(abs(x-goal), ans);
        for (const auto& x: sum2) ans = min(abs(x-goal), ans);

        int lft = 0, rht = 0;
        while (lft < sum1.size() and rht < sum2.size()) {
            auto x = sum1[lft] + sum2[rht];
            ans = min(abs(x - goal), ans);
            if (x < goal) lft++;
            else rht++;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.minAbsDifference({5,-7,3,5}, 6) << endl;
    cout << sol.minAbsDifference({7,-9,15,-2}, -5) << endl;
    // cout << sol.minAbsDifference({1,2,3}, -7) << endl;
    return 0;
}
