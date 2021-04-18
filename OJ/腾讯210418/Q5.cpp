#include <iostream>

using namespace std;



int main()
{
    // freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    auto ans = (double) N * N / (2 * N - 1);
    printf("%.6f", ans);
    
    return 0;
}
