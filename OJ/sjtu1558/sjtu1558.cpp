/*
    求移除哪几个数后，使得最长连续相同数的序列长度最长
    动态规划
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int MAX_N = 1e5+5;

int N, k;
int B[MAX_N];

int main(int argc, char const *argv[])
{
    #ifdef DEBUG

    freopen("sjtu1558/1.in", "r", stdin);

    #endif

    cin >> N >> k;
    for (int i=1; i<=N; ++i) scanf(" %d ", &B[i]);

    

    return 0;
}
