/*
leet045


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int jump(vector<int>& v) {
        // 8ms
        queue<int> Q; 
        int cur_i = -1, cur_max = 0, cnt = 0;

        do {
            if (Q.empty()) {
                cnt++;
                for (int i = cur_i + 1; i <= cur_max; ++i) {
                    Q.push(i);
                }
            }
            cur_i = Q.front(); Q.pop();
            if (v[cur_i] + cur_i > cur_max) cur_max = v[cur_i] + cur_i;
        } while (cur_max + 1 < v.size());

        return v.size() == 1 ? 0 : cnt;
    }
};

int main(int argc, char const *argv[])
{
    // vector v = { 0 };
    vector v = { 2, 3, 0, 1, 4 };

    Solution sol;   

    cout << sol.jump(v) << endl;
    return 0;
}
