/*
阿里0917


*/

// #include "../utils/LeetCpp.utils.hpp"
#include <iostream>

using namespace std;



int solution1(int N, int C) {
    int ans = 0;
    for (int y = C + 1; y <= N; y++)
    {
        ans += (N - C) / y - (1 - C) / y + 1;
    }
    return ans;
}



int main()
{
    freopen("in.txt", "r", stdin);

    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        cout << solution1(N, K) << endl;
    }
    
    return 0;
}
