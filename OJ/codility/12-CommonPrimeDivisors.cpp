/*
codility


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#include <functional>
int solution(vector<int> &A, vector<int> &B) {
    
    const int M = 65535;
    int f[M]{}; // f[x] 保存了 x 的最小质因数
    vector<int> primes; primes.reserve(10000);
    for (int x = 2; x < M; x++)
    {
        if (f[x] == 0) {
            f[x] = x; primes.push_back(x);
        }

        for (auto&& p: primes) {
            if (x * p >= M) break;
            
            f[x * p] = p; 
            
            // p 是第一个整除 x 的质数，之后 x * pk 的最小质因数应当是 p
            if (x % p == 0) break; 
        }
    }

    auto gcd = [](int x, int y) {
        if (y) while ((x %= y) and (y %= x) );
        return x + y;
    };

    function<bool(int, int)> ok = [&](int x, int d) {
        if (x == 1) return true;
        if (d == 1) return false;
        if (d >= M) {
            auto p = f[x]; 
            if (d % p) return false;
            while (d % p == 0) d /= p;
            while (x % p == 0) x /= p;
            return ok(x, d);
        }
        auto p = f[d]; 
        while (d % p == 0) d /= p;
        while (x % p == 0) x /= p;
        return ok(x, d);
    };

    int N = A.size(), ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] == 1 and B[i] == 1) {
            ans++; continue;
        }
        auto d = gcd(A[i], B[i]);
        if (d == 1) continue;
        if (ok(A[i]/d, d) and ok(B[i]/d, d)) ans++;
    }
    return ans;
}




int main(int argc, char const *argv[])
{
    vector A = {1, 15, 3}, B = {1, 75, 5};
    cout << solution(A, B) << endl;
    
    return 0;
}
