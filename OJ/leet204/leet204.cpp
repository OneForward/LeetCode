/*
leet204


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int countPrimes1(int n) {
        // 36ms, 88%, 埃氏筛, O(n log log n)
        vector<bool> f(n); int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (f[i]) continue; 
            for (int j = 2 * i; j < n; j += i)
            {
                f[j] = true;
            }
            cnt++;
        }
        return cnt;
    }
        // 欧拉筛法
        // min_prime[x] 保存了 数字 x 的最小质因数
        // int min_prime[1000010]{}, prime[100010]{};
        // int cnt = 0, M = 0;
        // for (const auto& x: A) M = max(M, x);

        // for (size_t x = 2; x <= M; x++)
        // {
        //     if (min_prime[x] == 0) {
        //         min_prime[x] = x; // x 是个质数
        //         prime[cnt++] = x;
        //     }
        //     for (size_t j = 0; j < cnt and x * prime[j] <= M; j++)
        //     {
        //         min_prime[x * prime[j]] = prime[j]; 
        //         if (x % prime[j] == 0) break; // pj 是第一个整除 x 的质数，之后的 x * pk 的最小质因数应当是 pj 了
        //     }
        // }
        
    int countPrimes(int n) {
        // 线性筛, O(n), 用于辅助分解质因数
        vector<bool> isPrime(n, true); int cnt = 0;
        vector<int> P;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i]) P.push_back(i), cnt++;
            for (int j = 0; j < P.size(); j++)
            {
                auto x = i * P[j];
                if (x >= n) break;
                isPrime[x] = false; 
                if (i % P[j] == 0) break;
            }
            
        }
        
        return cnt;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.countPrimes(10) << endl;
    cout << sol.countPrimes(0) << endl;
    cout << sol.countPrimes(1) << endl;
    cout << sol.countPrimes(2) << endl;
    cout << sol.countPrimes(3) << endl;
    return 0;
}
