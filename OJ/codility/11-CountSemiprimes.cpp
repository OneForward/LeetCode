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

#define SIZE(A) ((int)A.size())
#define ALL(A) A.begin(),A.end()
vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    const int M = 50005;
    int f[M]{}; // f[x] 保存了 x 的最小质因数
    vector<int> primes; primes.reserve(6000);
    for (int x = 2; x <= N; x++)
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
    vector<int> semiPrimes;
    for (int x = 2; x <= N; x++) {
        auto p = x / f[x] ;
        if (f[p] == p) semiPrimes.push_back(x);
    }

    vector<int> ans(P.size());
    for (int i = 0; i < SIZE(P); i++)
    {
        auto lft = lower_bound(ALL(semiPrimes), P[i]) - semiPrimes.begin();
        auto rht = lower_bound(ALL(semiPrimes), Q[i]+1) - semiPrimes.begin();
        ans[i] = rht - lft;
    }
    

    return ans;
}



int main(int argc, char const *argv[])
{
    int N = 26;
    vector P = {1,4,16}, Q = {26, 10, 20}, C = {4, 6, 7, 10, 2};
    cout << solution(N, P, Q) << endl;
    
    return 0;
}
