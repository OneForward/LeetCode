/*
lcp09


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int minJump1(const vector<int>& A) {
        // O(N^2), TLE
        int n = A.size();
        vector<int> f(n+1, INT_MAX); f[0] = 0;
        for (int i = 0; i < n; i++)
        {
            int rht = min(i+A[i], n);
            for (int j = i+1; j < rht; j++)
            {
                f[j] = min(f[j], f[i]+2);
            }
            f[rht] = min(f[rht], f[i]+1);
        }
        return f[n];
    }
    int minJump2(const vector<int>& A) {
        // O(N^2), 动态规划 + 剪枝， 200ms, 94%
        // f[i] 从 位置 i 跳到末尾需要的最少次数
        // 保证了 对 任意 i < j, 有 f[j] <= f[i] + 1
        int n = A.size();
        vector<int> f(n+1);
        for (int i = n-1; i >= 0; --i) {
            auto rht = min(A[i] + i, n);
            f[i] = f[rht] + 1;
            for (int j = i+1; j < rht and f[j] >= f[i] + 1; ++j) f[j] = f[i] + 1;
        }
        
        return f[0];
    }
    int minJump(const vector<int>& A) {
        // O(N^2), BFS， 200ms, 94%
        // 已访问的结点中, x + A[x] 是不连续的, [0, x] 是连续的
        // mx 保存的是 连续部分 的最大值
        int n = A.size(), cnt = 0;
        int mx = 0; 

        queue<int> Q; Q.push(0);
        while (Q.size()) {
            auto len = Q.size();
            for (size_t i = 0; i < len; i++)
            {
                auto x = Q.front();
                Q.pop();

                auto rht = x + A[x];
                if (rht >= n) return cnt + 1;
                if (rht > mx) Q.push(rht);
                for (int j = mx; j < x; ++j) Q.push(j);
                mx = max(mx, x);
            }
            cnt++;
        }
        
        return cnt;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minJump({2,5,1,1,1,}) << endl;
    return 0;
}
