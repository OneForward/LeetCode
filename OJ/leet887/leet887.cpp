/*
leet887


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

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



class Solution {
public:
    int superEggDrop1(int K, int N) {
        // 朴素的动态规划, O(K N^2)
        // 通过二分搜索可以优化到 O(K N log N)
        vector<vector<int>> f(K+1, vector<int>(N+1));
        f[0][0] = 0;
        for (int n = 1; n <= N; ++n) f[0][n] = 9999999;
        for (int k = 1; k <= K; ++k) {
            for (int n = 1; n <= N; ++n) {
                f[k][n] = INT_MAX;
                for (int i = 1; i <= n; ++i) {
                    f[k][n] = min(f[k][n], max( f[k-1][i-1], f[k][n-i] ) );
                }
                f[k][n]++;
            }
        }
        return f[K][N];
    }
    int superEggDrop2(int K, int N) {\
        // 根据OEIS查表寻找公式即可, O(m K), m <= 25
        if (K == 1) return N;
        if (K == 2) {
            int ans = 0;
            while (ans * (ans + 1) < 2 * N) ans++;
            return ans;
        }
        if (K == 3) {
            int ans = 0;
            while (ans * (ans * ans + 5) < 6 * N) ans++;
            return ans;
        }
        int m = 25;
        vector<vector<int>> f(K+1, vector<int>(m));
        vector<int> g(m);

        for (int i = 1; i <= K; ++i) {
            f[i][1] = 1;
        }
        
        for (int i = 1; i <= K; ++i) {
            for (int j = 2; j < m; ++j) {
                f[i][j] = f[i-1][j-1] + f[i][j-1];
            }
        }
        for (int j = 1; j < m; ++j) {
            g[j] = f[K][j] + g[j-1];
        }
        
        int ans = 0;
        while (g[ans] < N) ans++;
        return ans;
    }
    int superEggDrop3(int K, int N) {
        // 自底向上，考察操作T次最多可以确定多少层楼的情况
        // 随便扔一个鸡蛋
        // 碎了： 此处以上可以确定 f(K-1, T-1) 层
        // 没碎: 此处以下可以确定 f(K, T-1) 层
        // 递推: f(K, T) = f(K-1, T-1) + f(K, T-1) + 1 
        if (K == 1) return N;

        vector<vector<int>> f(K+1, vector<int>(N+1));
        for (int k = 1; k <= K; ++k) {
            for (int T = 1; T <= N; ++T) {
                f[k][T] = f[k-1][T-1] + f[k][T-1] + 1;
                if (f[k][T] >= N) {
                    if (k == K) return T;
                    else break;
                }
            }
        }
        return 1;
    }
    int superEggDrop(int K, int N) {
        // 自底向上，考察操作T次最多可以确定多少层楼的情况
        // 随便扔一个鸡蛋
        // 碎了： 此处以上可以确定 f(K-1, T-1) 层
        // 没碎: 此处以下可以确定 f(K, T-1) 层
        // 递推: f(K, T) = f(K-1, T-1) + f(K, T-1) + 1 
        vector<int> f(K+1);
        int T = 0;
        for ( ; f[K] < N; ++T) {
            for (int k = K; k > 0; --k) { 
                f[k] = f[k] + f[k-1] + 1;
            }
        }
        return T;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;  int K, N;
    K = 1, N = 2; cout << sol.superEggDrop(K, N) << ", " << sol.superEggDrop1(K, N)  << endl;
    K = 2, N = 6; cout << sol.superEggDrop(K, N) << ", " << sol.superEggDrop1(K, N)  << endl;
    K = 3, N = 14; cout << sol.superEggDrop(K, N) << ", " << sol.superEggDrop1(K, N)  << endl;
    K = 4, N = 1000; cout << sol.superEggDrop(K, N) << ", " << sol.superEggDrop1(K, N)  << endl;
    return 0;
}
