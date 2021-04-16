/*
leet119


*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> getRow(int numRows) {
        // 4ms
        vector<int> v; int prev, now;
        do {
            prev = 0;
            for (auto& vi: v) {
                now = vi;
                vi += prev;
                prev = now;
            }
            v.push_back(1);
        } while (numRows--);
        return v;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    auto ans = sol.getRow(0);
    
    for (auto ri: ans) cout << ri << ", "; cout << endl;
    
    return 0;
}
