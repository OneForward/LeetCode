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
using VI=vector<int>;
vector<int> solution(vector<int> &A, vector<int> &B) {
    int N = SIZE(A);
    const int MOD = 1<<30;
    VI f(N+1), ans(N);
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        f[i] = (f[i-1] + f[i-2]) % MOD;
    }
    
    for (int i = 0; i < N; i++)
    {
        ans[i] = f[A[i]] % (1<<B[i]);
    }
    return ans;
}





int main(int argc, char const *argv[])
{
    vector A = {4,4,5,5,1}, B = {3,2,4,3,1};
    cout << solution(A, B) << endl;
    
    return 0;
}
