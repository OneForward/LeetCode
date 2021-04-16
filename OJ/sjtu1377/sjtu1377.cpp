/*
    长度为N的数列 A[1..N] , 这N个数字恰好是1...N的一个排列, 这个序列的中值为B
    求出这个序列有多少个(连续)子序列 A[i..j] 满足： i <= j  且  j-i+1  为奇数, 且中值为 B
     O(N) 复杂度, 抽象大于中值的为+1, 小于中值的为-1，然后稍作统计即可
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 100000+11;
int N, B, ans = 0;
int A[MAX_N];

int* lft, *rht;
int lftMin(0), lftMax(0), rhtMin(0), rhtMax(0);

int x, mid_index;
inline int sign(const int& x) { return (x > 0) - (x < 0); }
inline int max(const int& a, const int& b) { return a > b ? a : b; }

int main(int argc, char const *argv[])
{    
    cin >> N >> B;
    for (int i=1; i<=N; ++i) 
        scanf("%d", &x), A[i] = sign(x-B); 


    for (int i=1; i<=N; ++i) if (A[i] == 0) { mid_index = i; break; }

    for (int i=mid_index-2; i>=1; --i) A[i] += A[i+1];
    for (int i=mid_index+2; i<=N; ++i) A[i] += A[i-1];

    for (int i=mid_index-1; i>=1; --i) {
        if (A[i] > lftMax) lftMax = A[i];
        if (A[i] < lftMin) lftMin = A[i];
    }

    for (int i=mid_index+1; i<=N; ++i) {
        if (A[i] > rhtMax) rhtMax = A[i];
        if (A[i] < rhtMin) rhtMin = A[i];
    }


    lft  = new int[ lftMax-lftMin+1 ];
    for (int i=0; i <= lftMax-lftMin; ++i) lft[i] = 0;
    for (int i=mid_index-1; i>=1; --i) lft[A[i]-lftMin]++;

    rht  = new int[ rhtMax-rhtMin+1 ];
    for (int i=0; i <= rhtMax-rhtMin; ++i) rht[i] = 0;
    for (int i=mid_index+1; i<=N; ++i) rht[A[i]-rhtMin]++;


    for (int i=max(lftMin, -rhtMax); i<=-rhtMin and i<=lftMax ; ++i) 
        ans += lft[i-lftMin] * rht[-rhtMin-i]; 
    ans += (lft[-lftMin]+rht[-rhtMin]+1);
    cout << ans;
    return 0;
}
