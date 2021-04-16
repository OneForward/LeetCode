/*
kickstart2021-A-L-Shaped-Plots


*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);

    int T, R, C;
    const int N = 8;
    int M[N][N]{};
    int V1[N][N]{};
    int V2[N][N]{};
    int H1[N][N]{};
    int H2[N][N]{};
    
    cin >> T;
    
    for (int test = 1; test <= T; ++test) {
        cin >> R >> C;
        for (int r = 1; r <= R; ++r) {
            for (int c = 1; c <= C; ++c) {
                cin >> M[r][c];
            }
        }
        for (int r = 1; r <= R; ++r) {
            for (int c = 1; c <= C; ++c) {
                if (M[r][c]) H1[r][c] = H1[r][c-1] + 1;
            }
            for (int c = C; c >= 1; --c) {
                if (M[r][c]) H2[r][c] = H2[r][c+1] + 1;
            }
        }
        for (int c = 1; c <= C; ++c) {
            for (int r = 1; r <= R; ++r) {
                if (M[r][c]) V1[r][c] = V1[r-1][c] + 1;
            }
            for (int r = R; r >= 1; --r) {
                if (M[r][c]) V2[r][c] = V2[r+1][c] + 1;
            }
        }

        int cnt = 0;
        for (int r = 1; r <= R; ++r) {
            for (int c = 1; c <= C; ++c) {
                if ( M[r][c] == 0 ) continue;
                cnt += max(min(V1[r][c]/2, H1[r][c]) - 1, 0);
                cnt += max(min(V2[r][c]/2, H1[r][c]) - 1, 0);
                cnt += max(min(H1[r][c]/2, V1[r][c]) - 1, 0);
                cnt += max(min(H2[r][c]/2, V1[r][c]) - 1, 0);
                cnt += max(min(V1[r][c]/2, H2[r][c]) - 1, 0);
                cnt += max(min(V2[r][c]/2, H2[r][c]) - 1, 0);
                cnt += max(min(H1[r][c]/2, V2[r][c]) - 1, 0);
                cnt += max(min(H2[r][c]/2, V2[r][c]) - 1, 0);
            }
        }

        for (int r = 1; r <= R; ++r) {
            for (int c = 1; c <= C; ++c) {
                M[r][c] = V1[r][c] = V2[r][c] = H1[r][c] = H2[r][c] = 0;
            }
        }

        printf("Case #%d: %d\n", test, cnt);
    }
}
