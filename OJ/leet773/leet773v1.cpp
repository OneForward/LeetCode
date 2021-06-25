/*
leet773


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

class Solution {
public:
    int slidingPuzzle(const vector<vector<int>>& board) {
        bool visited[1000000]{};
        int state[][3] = {{}, {}};

        using Tuple = tuple<int, int, int>;
        auto getState = [&] () -> Tuple {
            int h = 0, r, c;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    auto  x = state[i][j];
                    if (x == 0) r = i, c = j;
                    h = h * 10 + x;
                }
            }
            return {h, r, c};
        };  

        auto setState = [&](int h) {
            for (int i = 2 - 1; i >= 0; i--)
            {
                for (int j = 3 - 1; j >= 0; j--)
                {
                    state[i][j] = h % 10; h /= 10;
                }
                
            }
        
        };
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                state[i][j] = board[i][j];
            }
        }



        const int DIR[][2] = {{1,0}, {-1,0}, {0, 1}, {0,-1}};

        auto [h, x, y] = getState(); int ans = 0; visited[h] = true;
        
        queue<Tuple> Q;  Q.push({h, x, y});

        while (Q.size()) {
            int len = Q.size(); ans++;
            while (len--) {
                auto [h, x, y] = Q.front(); Q.pop();
                setState(h);
                // printf("h = %06d\n", h);
                for (auto&& [dx, dy]: DIR) {
                    auto r = x + dx, c = y + dy;
                    if (r >= 2 or r < 0 or c >= 3 or c < 0 ) continue;
                    
                    swap(state[x][y], state[r][c]);
                    auto [newh, _, __] = getState();
                    if (newh == 123450) goto last;
                    if (not visited[newh]) Q.push({newh, r, c}), visited[newh] = true;
                    swap(state[x][y], state[r][c]);
                }
            }
        }
        return -1;
        last: return ans;

    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.slidingPuzzle({{1,2,3},{4,0,5}}) << endl;
    cout << sol.slidingPuzzle({{1,2,3},{5,4,0}}) << endl;
    cout << sol.slidingPuzzle({{4,1,2},{5,0,3}}) << endl;
    cout << sol.slidingPuzzle({{3,2,4},{1,5,0}}) << endl;
    return 0;
}
