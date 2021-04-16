
/*
    [DFS]
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int T;
int MAZE[6][6];
int srcX, srcY, dstX, dstY;

int dfs(int x,int y) {
    if (x < 0 or x > 6 or y < 0 or y > 6) return 0;
    if (x == dstX and y == dstY) return 0;
    int ans = 0;
    ans = dfs(x+1, y);
    dfs(x, y+1);
    dfs(x-1, y);
    dfs(x, y-1);
}

int dfs() {
    return dfs(srcX, srcY);
}

int main(int argc, char const *argv[])
{
    #ifdef DEBUG
    freopen("sjtu1564/1.in", "r", stdin);
    #endif

    cin >> T;
    while (T--) {
        for (int i=0; i<6; ++i)
            for (int j=0; j<6; ++j) scanf(" %d ", &MAZE[i][j]);
        scanf(" %d %d %d %d", &srcX, &srcY, &dstX, &dstY;)
        dfs();
    }
    return 0;
}