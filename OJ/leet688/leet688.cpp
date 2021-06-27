/*
leet688


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> f(N+4, vector<double>(N+4)), g;
        for (int i = 0; i < N+4; ++i) {
            f[i][0] = f[i][1] = f[i][N+2] = f[i][N+3] = 1;
            f[0][i] = f[1][i] = f[N+2][i] = f[N+3][i] = 1;
        }

        const int D[][2] = {
            {1, 2}, {1, -2}, {2, 1}, {2, -1},
            {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1},
        };
        const int MOD = 1e9 + 7;
        while (K--) {
            g = f;
            for (int i = 2; i < N+2; ++i) {
                for (int j = 2; j < N+2; ++j) {
                    f[i][j] = 0;
                    for (const auto& [dx, dy]: D) {
                        auto x = i + dx, y = j + dy;
                        f[i][j] += g[x][y] / 8.; 
                    }
                }
            }
        }
        return 1. - f[r+2][c+2];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.knightProbability(3, 2, 0, 0) << endl;
    return 0;
}
