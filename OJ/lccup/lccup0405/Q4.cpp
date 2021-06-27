/*
lccup0405


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    bool escapeMaze(const vector<vector<string>>& maze) {
        enum State { Normal, Temp, Forever };
        struct Tuple
        {
            State state; int x, y, x0, y0;
        };
        queue<Tuple> Q; Q.push({Normal, 0, 0, 0, 0});
        int time = 0, R = maze[0].size(), C = maze[0][0].size();
        const int Dir[][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (Q.size()) {
            int n = Q.size(); time++;
            if (time == maze.size()) break;
            auto&& M = maze[time];
            while (n--) {
                auto [state, x, y, x0, y0] = Q.front(); Q.pop();
                for (auto&& [dx, dy]: Dir) {
                    auto r = x + dx, c = y + dy;
                    if ( r < 0 or r >= R or c < 0 or c >= C ) continue;
                    if (M[r][c] == '.') Q.push({state, r, c, x0, y0});
                    else if (state == Forever) {
                        if (r == x0 and c == y0) Q.push({state, r, c, x0, y0});
                    }
                    else if (state == Normal) {
                        Q.push({Temp, r, c, x0, y0});
                        Q.push({Forever, r, c, r, c});
                    }
                }
            }
        }
        
        while (Q.size()) {
            auto&& [state, x, y, x0, y0] = Q.front(); Q.pop();
            if (x == R - 1 and y == C - 1) return true;
        }
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
