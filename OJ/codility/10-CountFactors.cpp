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

#include <vector>
int solution(int N) {
    const int M = 65536;
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
    int ans = 1;
    for (auto&& p: primes) {
        if (p > N) break;
        auto cnt = 0;
        while (N % p == 0) {
            cnt++; N /= p;
        }
        ans *= (1 + cnt);
    }
    return N == 1 ? ans : ans * 2;
}



int main(int argc, char const *argv[])
{
    vector A = {1, 4, 5, 8}, B = {4, 5, 9, 10}, C = {4, 6, 7, 10, 2};
    cout << solution(1) << endl;
    cout << solution(2) << endl;
    cout << solution(3) << endl;
    cout << solution(4) << endl;
    cout << solution(24) << endl;
    cout << solution(5621892) << endl;
    cout << solution(INT_MAX) << endl;
    
    return 0;
}
