/*
leet673


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int findNumberOfLIS(const VI& A) {
        // wrong answer
        // O(N log N), 动态规划
        // len[i]: 保存以 A[i] 为终点的 LIS 的长度
        // cnt[i]: 保存以 A[i] 为终点的 LIS 的个数
        // 对于 j < i, A[j] < A[i], 则 len[i] = max(len[j]+1, len[i])
        // 对于贡献了 len[i] = len[j] + 1 的 j, cnt[i] += cnt[j]
        // 最后 ans 等于所有 len[i] = maxlen 的 i 贡献的 cnt[i] 之和
        int N = A.size();
        VI S, cnt(N+1, 0); S.reserve(N);
        cnt[0] = 1;
        for (auto&& x: A) {
            auto pos = lower_bound(ALL(S), x);
            auto len = pos - S.begin() + 1;
            if (pos == S.end()) S.push_back(x);
            else *pos = x;
            cnt[len] += cnt[len-1];
        }
        cout << S << endl;
        cout << cnt << endl;

        return cnt[S.size()];
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findNumberOfLIS({1,3,5,4,7}) << endl;
    cout << sol.findNumberOfLIS({2,2,2,2,2}) << endl;
    cout << sol.findNumberOfLIS({1,2,4,3,5,4,7,2}) << endl;
    return 0;
}
