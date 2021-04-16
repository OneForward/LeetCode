/*
leet399


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

    vector<double> calcEquation(const vector<vector<string>>& equations, const vector<double>& values, const vector<vector<string>>& queries) {
        unordered_map<string, string> P;
        unordered_map<string, double> D;
        using Pair = pair<string, double>;
        function<Pair(const string&, bool)> find = [&](const string& x, bool insert)->Pair {
            if (P.find(x) == P.end()) {
                if (insert) { P[x] = {}; D[x] = 1.; return {x, 1.}; }
                else return {{}, -1.};
            }
            if (P[x].empty()) return {x, 1.};
            auto [parent, dist] = find(P[x], insert);
            P[x] = parent; D[x] *= dist;
            return {parent, D[x]};
        };

        int N = equations.size();
        for (int i = 0; i < N; ++i) {
            auto&& x = equations[i] [0], &&y = equations[i][1];
            auto&& d = values[i];
            auto&& [rx, dx] = find(x, true);
            auto&& [ry, dy] = find(y, true);
            if (rx == ry) continue;
            P[ry] = rx; D[ry] = d * dx / dy; 
        }

        vector<double> ans; ans.reserve(queries.size());
        for (auto&& query: queries) {
            auto&& x = query [0], &&y = query[1];
            auto&& [rx, dx] = find(x, false);
            auto&& [ry, dy] = find(y, false);
            ans.push_back( rx.size() and rx == ry ? dy / dx : -1. );
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.calcEquation({{"a","b"},{"b","c"}},  {{2.0,3.0}}, { {"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}}) << endl;
    cout << sol.calcEquation({{"a","b"},{"b","c"},{"bc","cd"}}, {1.5,2.5,5.0}, {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}}) << endl;
    cout << sol.calcEquation( {{"a","b"}},  {0.5},  {{"a","b"},{"b","a"},{"a","c"},{"x","y"}}) << endl;
    cout << sol.calcEquation( {{"a","e"}, {"b","e"}},  {4, 3},  {{"e","e"}}) << endl;
    return 0;
}
