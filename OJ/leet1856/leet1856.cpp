/*
leet1856


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()


class Solution {
public:
    int maxSumMinProduct(const vector<int>& A) {
        // 单调栈
        const int MOD = 1e9 + 7, MAX = 100005;
        long long S[MAX]{}, ans = 0; 
        int N = A.size();
        int lft[MAX], rht[MAX];
        vector<int> v1, v2;
        for (int i = 0; i < N; i++)
        {
            S[i+1] = S[i] + A[i];
            while (v1.size() and A[v1.back()] >= A[i]) v1.pop_back();
            while (v2.size() and A[v2.back()] >= A[N-1-i]) v2.pop_back();
            lft[i] = v1.size() ? v1.back() + 1 : 0; 
            rht[N-1-i] = v2.size() ? v2.back() - 1 : N - 1; 
            v1.push_back(i); v2.push_back(N-1-i);
        }

        for (int i = 0; i < N; i++)
        {
            ans = max(ans, A[i] * (S[rht[i] + 1] - S[lft[i]]) );
        }

        return ans % MOD;
    }
};

class SolutionWrong {
public:
    int maxSumMinProduct(const vector<int>& A) {
        // 错误
        multiset<int> S(ALL(A));
        int P = reduce(ALL(A), 0), ans = 0;
        int lft = 0, rht = A.size() - 1;
        while (lft <= rht) {
            ans = max(ans, P * *S.begin());
            int x;
            if (A[lft] < A[rht]) x = A[lft++];
            else x = A[rht--];
            P -= x; S.erase(S.find(x));
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxSumMinProduct({1,2,3,2}) << endl;
    cout << sol.maxSumMinProduct({2,3,3,1,2}) << endl;
    cout << sol.maxSumMinProduct({3,1,5,6,4,2}) << endl;
    cout << sol.maxSumMinProduct({2,5,4,2,4,5,3,1,2,4}) << endl;
    return 0;
}
