/*
lccup0405


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    bool escapeMaze(const vector<vector<string>>& maze) {
        bool f[105][55][55][2][2][2]{};
        const int Dir[][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto T = maze.size(), R = maze[0].size(), C = maze[0][0].length();
        function<void(int, int, int, int, int, int)> dfs = [&](int t,int x,int y,int use_tmp,int use_all,int use_total)
        {
            if (f[t][x][y][use_tmp][use_all][use_total]) return;
            f[t][x][y][use_tmp][use_all][use_total] = 1;
            if (t == T-1) return;
            if (use_total || maze[t+1][x][y]=='.') dfs(t+1,x,y,use_tmp,use_all,use_total);
            for (auto&& [dx, dy]: Dir) {
                auto r = x + dx, c = y + dy;
                if ( r < 0 or r >= R or c < 0 or c >= C ) continue;
                if (maze[t+1][r][c] == '.') dfs(t+1,r,c,use_tmp,use_all,0);
                if (!use_tmp) dfs(t+1,r,c,1,use_all,0);
                if (!use_all) dfs(t+1,r,c,use_tmp,1,1);
            }
        };
        
        dfs(0,0,0,0,0,0);
        for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    for (int l = 0; l < 2; ++l)
                            if (f[T-1][R-1][C-1][j][k][l]) return true;
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.escapeMaze({{".#.","#.."},{"...",".#."},{".##",".#."},{"..#",".#."}}) << endl;
    cout << sol.escapeMaze({{".#.","..."},{"...","..."}}) << endl;
    cout << sol.escapeMaze({{"...","...","..."},{".##","###","##."},{".##","###","##."},{".##","###","##."},{".##","###","##."},{".##","###","##."},{".##","###","##."}}
) << endl;
 
    return 0;
}
