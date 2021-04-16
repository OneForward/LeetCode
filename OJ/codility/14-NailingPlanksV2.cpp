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


#include <cstring>
#define SIZE(A) ((int)A.size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    // O((M+N) log M)

    auto M = SIZE(C), N = SIZE(A);
    
    int f[60005]{};
    int lft = 1, rht = M+1;

    int ans = -1;
    while (lft < rht) {
        auto mid = (lft + rht) / 2;
        memset(f, 0, sizeof f);

        REP(i, mid) f[C[i]] = 1;
        FOR(i, 1, 2 * M + 1) f[i] += f[i-1];

        auto ok = true;
        REP(i, N) {
            if (f[B[i]] == f[A[i] - 1]) { ok = false; break; }
        }

        if (ok) { rht = mid; ans = mid;}
        else lft = mid + 1;
    }

    return ans;
}




int main(int argc, char const *argv[])
{
    vector A = {1, 4, 5, 8}, B = {4, 5, 9, 10}, C = {4, 6, 7, 10, 2};
    cout << solution(A, B, C) << endl;
    
    return 0;
}
