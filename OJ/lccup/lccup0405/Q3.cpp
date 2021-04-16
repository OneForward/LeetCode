/*
lccup0405


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int magicTower(const vector<int>& A) {
        auto f = A; f[0] += 1;
        int n = A.size(), cnt = 0, sum = 0;
        priority_queue<int> Q;
        for (int i = 1; i < n; i++)
            f[i] += f[i-1];
        if (f.back() <= 0) return -1;
        for (int i = 0; i < n; i++) {
            auto x = f[i], ai = A[i];
            if (A[i] < 0)  Q.push(-A[i]);
            while (x + sum <= 0) {
                if (Q.empty()) return -1;
                sum += Q.top(); Q.pop(); cnt++;
            }
        }
        return cnt;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.magicTower({100 ,100,100,-250,-60,-140,-50,-50,100,150}) <<  endl;
    cout << sol.magicTower({100 ,100,100,-150,-60,-160,-50,-50,100,150}) <<  endl;
    // cout << sol.magicTower({-200,-300,400,0}) <<  endl;
    return 0;
}
