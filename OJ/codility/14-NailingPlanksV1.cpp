/*
codility


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;


#include <deque>
#define SIZE(A) ((int)A.size())
using VI = vector<int>;
const int INF = 2e9;

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    // O(M+N) 单调队列
    // nail: 每个位置表示该位置上钉子的最小编号（可能同一个位置有多个钉子，取编号最小的），没有钉子的位置值为无穷大
    // plank: plank[x]表示右端点为x的木板的最大左边界，没有木板的话，认为边界是0

    auto M = SIZE(C), N = SIZE(A);
    int R = 2 * M + 1;

    VI nail(R, INF);
    for (int i = M - 1; i >= 0; i--)
    {
        nail[C[i]] = i;
    }

    VI plank(R, 0);
    for (int i = 0; i < N; i++)
    {
        plank[B[i]] = max(plank[B[i]], A[i]);
    }
    
    deque<int> Q; // Q 中的元素是单增的，且相对 nail 也是单增的
    int lft = 0, rht = 0, ans = 0;
    for (int i = 1; i < R; i++)
    {
        if (plank[i] <= lft) continue;
        lft = plank[i];

        while (Q.size() and Q.front() < lft) Q.pop_front();
        for (rht = max(rht, lft); rht <= i; rht++)
        {
            while (Q.size() and nail[Q.back()] >= nail[rht]) Q.pop_back();
            Q.push_back(rht);
        }
        
        ans = max(ans, nail[Q.front()]);
        if (ans == INF) return -1;
    }
    return ans + 1;
    
}




int main(int argc, char const *argv[])
{
    vector A = {1, 4, 5, 8}, B = {4, 5, 9, 10}, C = {4, 6, 7, 10, 2};
    cout << solution(A, B, C) << endl;
    
    return 0;
}
