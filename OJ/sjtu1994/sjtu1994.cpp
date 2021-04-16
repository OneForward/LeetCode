/*
    dfs, 邻接数组, 求连通分量的个数
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 511;

int Maze[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int N, M, unvisitedCnt = 0, ans = 0;
bool over = false;

bool isvalid(const int& x, const int& y) {
    if (1 <= x and x <= N and 1 <= y and y <= M and
        Maze[x][y] != -1 and not visited[x][y]) return true;
    return false;
}
void dfs(const int& ux, const int& uy) {
    visited[ux][uy] = true;
    if (isvalid(ux-1, uy)) dfs(ux-1, uy);
    if (isvalid(ux+1, uy)) dfs(ux+1, uy);
    if (isvalid(ux, uy-1)) dfs(ux, uy-1);
    if (isvalid(ux, uy+1)) dfs(ux, uy+1);
}

int main(int argc, char const *argv[])
{

    cin >> N >> M;
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=M; ++j)
            scanf(" %d ", &Maze[i][j]);
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=M; ++j) 
            visited[i][j] = false; 

    while (not over) {
        over = true;
        for (int i=1; i<=N; ++i)
            for (int j=1; j<=M; ++j) 
                if (Maze[i][j] == 0 and not visited[i][j]) dfs(i, j), ans++, over = false;
    }
    cout << ans;
    return 0;
}