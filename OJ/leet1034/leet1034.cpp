/*
leet1034


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>> grid, int row, int col, int color) {
        const int DIR[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        bool visited[51][51]{};
        int R = grid.size(), C = grid[0].size();
        int oldcolor = grid[row][col];
        auto newgrid = grid;
        function<void(int, int)> f = [&](int x, int y) {
            visited[x][y] = true;
            auto isborder = false;
            for (auto&& [dx, dy]: DIR) {
                auto r = x + dx, c = y + dy;
                if (r < 0 or r >= R or 
                    c < 0 or c >= C or 
                    grid[r][c] != oldcolor) { 
                        isborder = true; continue;
                }
                if (visited[r][c]) continue;
                f(r, c);
            }
            if (isborder) newgrid[x][y] = color;
        };

        f(row, col);
        return newgrid;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.colorBorder({
        {1, 1},
        {1, 2},}, 0, 0, 3
    ) << endl;
    cout << sol.colorBorder({
        {1, 2, 2},
        {2, 3, 2},}, 0, 1, 3
    ) << endl;
    cout << sol.colorBorder({
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}}, 1, 1, 2
    ) << endl;
    return 0;
}
