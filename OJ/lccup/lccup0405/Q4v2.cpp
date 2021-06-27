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
        function<bool(int, int, int, int, int, int)> dfs = [&](int t,int x,int y,int use_tmp,int use_all,int use_total)
        {
            if (f[t][x][y][use_tmp][use_all][use_total]) return false;
            if (t == T-1) return x == R-1 and y == C-1;
            if (use_total || maze[t+1][x][y]=='.') if (dfs(t+1,x,y,use_tmp,use_all,use_total)) return true;
            for (auto&& [dx, dy]: Dir) {
                auto r = x + dx, c = y + dy;
                if ( r < 0 or r >= R or c < 0 or c >= C ) continue;
                if (maze[t+1][r][c] == '.') if ( dfs(t+1,r,c,use_tmp,use_all,0) ) return true;
                if (!use_tmp) if ( dfs(t+1,r,c,1,use_all,0)) return true;
                if (!use_all) if ( dfs(t+1,r,c,use_tmp,1,1)) return true;
            }
            f[t][x][y][use_tmp][use_all][use_total] = true;
            return false;
        };
        
        return dfs(0,0,0,0,0,0);
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
