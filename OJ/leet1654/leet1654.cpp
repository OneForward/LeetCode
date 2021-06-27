/*
leet1654


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int minimumJumps(const vector<int>& forbidden, int a, int b, int target) {
        // BFS
        bool visited[6005]{true};
        for (auto&& x: forbidden) visited[x] = true;

        queue<pair<int, bool>> Q; Q.push({0, false}); 
        int cnt = 0;
        while (Q.size()) {
            int len = Q.size(); 
            while (len--) {
                auto [x, once_back] = Q.front(); Q.pop(); 
                if (x == target)  return cnt;
                if (x - b >= 0 and not once_back and not visited[x - b]) Q.push({x - b, true}), visited[x - b] = true;
                if (x + a <= 6000 and not visited[x + a]) Q.push({x + a, false}), visited[x + a] = true;
            }
            cnt++;
        }
        return -1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minimumJumps({14,4,18,1,15}, 3, 15, 9) << endl;
    cout << sol.minimumJumps({8,3,16,6,12,20}, 15,  13,  11) << endl;
    cout << sol.minimumJumps({1,6,2,14,5,17,4}, 16,  9,  7) << endl;
    cout << sol.minimumJumps({162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98}, 29, 98, 80) << endl;
    return 0;
}
