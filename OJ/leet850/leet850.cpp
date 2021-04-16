/*
leet850


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

const int MOD = 1e9+7;
class Solution {
public:
    int rectangleArea(const vector<vector<int>>& rectangles) {
        // 扫描线, O(N^2), 4ms
        // 对每一个 y, 获得 当前为止的 合并区间 [L1, R1], ..., [Ln, Rn] 的总长度
        // 每次只做一次 添加 或 一次删除 [L, R], 可以在 O(N) 的时间内获得
        const int IN = 0, OUT = 1;
        using Tuple = tuple<int, int, int, int>;
        vector<Tuple> events;
        for (const auto& v: rectangles) { 
            auto x1 = v[0], y1 = v[1], x2 = v[2], y2 = v[3];
            events.push_back({y1, IN, x1, x2});
            events.push_back({y2, OUT, x1, x2});
        }
        sort(events.begin(), events.end()); // O(N log N)

        using Pair = pair<int, int>;
        vector<Pair> active;
        
        auto query = [&]() {
            long long ans = 0; int hi = 0;
            for (const auto& [x1, x2]: active) { // O(N)
                if (x2 < hi) continue;
                ans += x2 - max(hi, x1), hi = x2;
            }
            return ans;
        };

        int y1 = get<0>(events[0]); long long ans = 0;
        for (const auto& [y2, type, x1, x2]: events) {// N loops
            if (y2 > y1) ans += query() * (y2 - y1), ans %= MOD;
            auto pos = lower_bound(active.begin(), active.end(), Pair{x1, x2}); // O(log N)
            if (type == IN) 
                active.insert(pos, Pair{x1, x2}); // O(N)
            else 
                active.erase(pos); // O(N)
            y1 = y2;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.rectangleArea({{0,0,2,2},{1,0,2,3},{1,0,3,1}}) << endl;
    cout << sol.rectangleArea({{0,0,1000000000,1000000000}}) << endl;
    cout << sol.rectangleArea({{0,0,1,1}, {2,2,3,3}}) << endl;
    cout << sol.rectangleArea({{471,0,947,999},{780,0,823,320},{868,0,948,538},{907,0,911,673},{929,0,952,596},{458,0,889,669},{156,0,364,754},{900,0,973,236},{406,0,620,454},{773,0,946,538},{407,0,834,23},{759,0,858,526},{431,0,776,599},{969,0,979,30},{642,0,737,339},{239,0,448,183},{260,0,517,903},{14,0,674,976},{251,0,850,112},{57,0,794,395},{595,0,728,149},{970,0,989,36},{496,0,954,791},{447,0,832,805},{829,0,939,100},{169,0,568,501},{704,0,969,411},{607,0,609,221},{935,0,953,437},{47,0,670,130},{794,0,799,230},{943,0,959,90},{332,0,337,732},{123,0,228,344},{281,0,487,598},{381,0,732,443},{235,0,391,548},{646,0,930,20},{219,0,675,95},{8,0,212,227},{138,0,704,658},{368,0,782,707},{810,0,826,957},{543,0,697,654},{887,0,986,180},{837,0,900,228},{280,0,391,331},{180,0,229,42},{201,0,489,687},{648,0,680,732},{228,0,630,922},{886,0,960,56},{946,0,955,522},{903,0,992,464},{557,0,860,38},{89,0,268,642},{669,0,774,185},{1,0,724,374},{395,0,923,782},{82,0,230,550},{166,0,166,808},{441,0,644,435},{497,0,823,224},{372,0,973,556},{188,0,846,127},{226,0,396,535},{869,0,945,575},{406,0,526,795},{781,0,795,569},{563,0,831,991},{466,0,486,641},{274,0,855,529},{61,0,819,364},{285,0,421,101},{193,0,950,748},{320,0,655,836},{207,0,627,945},{782,0,899,56},{578,0,970,913},{499,0,684,205},{490,0,877,16},{483,0,668,915},{364,0,741,16}}) << endl;

    return 0;
}
