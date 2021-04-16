/*
kickstart2021-A-K-Goodness-String


*/


#include <iostream>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);

    int T, N, K;
    string s;
    
    cin >> T;
    
    for (int test = 1; test <= T; ++test) {
        cin >> N >> K >> s;
        for (int i = 0; i < N/2; ++i) {
            if (s[i] != s[N-i-1]) K--;
        }
        printf("Case #%d: %d\n", test, abs(K));
    }
}
