/*
leet837


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
#include "../utils/LeetCpp.utils.hpp"
using namespace std;



class Solution {
public:
    double new21Game1(int N, int K, int W) {
        // TLE
        // f[k]： 从 0 开始经过能到达 k 的概率
        // f[k] = (f[k-W] + ... + f[k-1]) / W
        if (K+W < N) return 1;

        vector<double> f(K+W+1);
        f[0] = 1.;
        for (int k = 1; k <= K+W; ++k) { 
            for (int i = max(k-W, 0); i < min(k, K); ++i) { 
                f[k] += f[i];
            }
            f[k] /= (double)W;
        }

        cout << f;
        double p1 = 0, p2;
        for (int i = K; i <= N; ++i) { 
            p1 += f[i];
        }
        p2 = p1;
        for (int i = N+1; i <= K+W; ++i) { 
            p2 += f[i];
        }
        return p1 / p2;
    }


    double new21Game(int N, int K, int W) {
        // 优化一下空间和时间
        // f[k]： 从 0 开始经过能到达 k 的概率
        // f[k] = (f[0] + ... + f[k-1]) / W, 0 <= k <= K 
        // f[k] = (f[k-W] + ... + f[k-1]) / W, W <= k <= K 
        // f[k] = (f[k-W] + ... + f[K]) / W, k > K
        if (K+W <= N + 1) return 1;
        if (K == 0) return 1;

        vector<double> f(K+W+1);
        f[0] = 1.; f[1] = 1. / W;
        for (int k = 2; k <= K+W; ++k) { 
            f[k] = (W + 1) * f[k-1];
            if (k > W) f[k] -= f[k-W-1];
            if (k > K) f[k] -= f[k-1];
            f[k] /= (double)W;
        }
        cout << f;

        double p1 = 0, p2;
        for (int i = K; i <= N; ++i) { 
            p1 += f[i];
        }
        p2 = p1;
        for (int i = N+1; i <= K+W; ++i) { 
            p2 += f[i];
        }
        return p1 / p2;
    }

    double new21GameOfficial(int N, int K, int W) {
        // f[k] : 从 分数 k 开始获胜的概率
        // f[k] = (f[k+1] + ...  + f[k+W]) / W 
        // 注：测例默认了 K+W >= N
        if (K == 0) {
            return 1.0;
        }
        vector<double> f(K + W);
        for (int i = K; i <= N && i < K + W; i++) {
            f[i] = 1.0;
        }
        f[K - 1] = 1.0 * min(N - K + 1, W) / W;
        for (int i = K - 2; i >= 0; i--) {
            f[i] = f[i + 1] - (f[i + W + 1] - f[i + 1]) / W;
        }
        return f[0];
    }

};

int main(int argc, char const *argv[])
{
    Solution sol;   

    cout << sol.new21Game(0, 0, 1) << endl;
    cout << sol.new21Game1(0, 0, 1) << endl;
    // cout << sol.new21Game(10, 1, 10) << endl;
    // cout << sol.new21Game(6, 1, 10) << endl;
    // cout << sol.new21Game(21, 17, 10) << endl;
    // cout << sol.new21Game1(21, 17, 10) << endl;
    return 0;   
}
