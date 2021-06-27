/*
leet5724


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(const vector<int>& A, const vector<int>& B) {
        int n = A.size(); auto sum = 0L;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n ; ++i) {
            sum += abs(A[i] - B[i]);
        }
        int iB[100005]{};
        auto cmp = [&](int i, int j) { return B[i] < B[j]; };
        iota(iB, iB + n, 0);
        sort(iB, iB + n, cmp);
        auto Asorted = A;
        sort(Asorted.begin(), Asorted.end());

        auto delta = 0, pA = 0;
        for (auto&& i: iB) {
            while (pA < n and Asorted[pA] < B[i]) pA++;
            if (pA >= 1) delta = max( abs(A[i] - B[i]) - abs(Asorted[pA-1] - B[i]), delta );
            if (pA < n) delta = max( abs(A[i] - B[i]) - abs(Asorted[pA] - B[i]), delta );
        }
        return (sum - delta) % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minAbsoluteSumDiff({1,7,5}, {2,3,5}) << endl;
    cout << sol.minAbsoluteSumDiff({2,4,6,8,10}, {2,4,6,8,10}) << endl;
    cout << sol.minAbsoluteSumDiff({1,10,4,4,2,7}, {9,3,5,1,7,4}) << endl;
    return 0;
}
