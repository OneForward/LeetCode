/*
leet391


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
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;


class Solution {
public:
    bool isRectangleCover(vector<vector<int>> rectangles) {
        // O(N log N),  判断重叠 与 面积求和
        // 1. 每个顶点的重叠次数必定恰为偶数 2. 小矩形面积之和必定恰与大矩形相等
        int X1 = INT_MAX, X2 = INT_MIN, Y1 = INT_MAX, Y2 = INT_MIN;
        map<pair<int, int>, int> M; int area = 0;
        for (const auto& v: rectangles) {
            auto x1 = v[0], y1= v[1], x2 = v[2], y2 = v[3];
            X1 = min(x1, X1); X2 = max(X2, x2);
            Y1 = min(y1, Y1); Y2 = max(Y2, y2);
            area += (x2 - x1) * (y2 - y1);
            M[{x1, y1}]++;
            M[{x1, y2}]++;
            M[{x2, y1}]++;
            M[{x2, y2}]++;
        }
        if (area != (X2 - X1) * (Y2 - Y1)) return false;
        M[{X1, Y1}]++;
        M[{X1, Y2}]++;
        M[{X2, Y1}]++;
        M[{X2, Y2}]++;
        for (const auto& [k, v]: M) if (v % 2) return false;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    cout << boolalpha;

    Solution sol;   
    cout << sol.isRectangleCover({
            {1,1,3,3},
            {1,1,3,3},
            }) << endl;
    cout << sol.isRectangleCover({
            {1,1,3,3},
            {3,1,4,2},
            {3,2,4,4},
            {1,3,2,4},
            {2,3,3,4}
            }) << endl;
    cout << sol.isRectangleCover({
            {1,1,2,3},
            {1,3,2,4},
            {3,1,4,2},
            {3,2,4,4}
            }) << endl;
    cout << sol.isRectangleCover({
            {1,1,3,3},
            {3,1,4,2},
            {1,3,2,4},
            {3,2,4,4}
            }) << endl;
    cout << sol.isRectangleCover({
            {1,1,3,3},
            {3,1,4,2},
            {1,3,2,4},
            {3,2,4,4}
            }) << endl;
    return 0;
}
