/*
leet332


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}


class Solution1 {
public:
    vector<string> ans;
    unordered_map<string, deque<string>> M;
    int n;

    bool recursive(string& start) {
        // 朴素的递归解法
        if (ans.size() == n) return true;
        auto p = M.find(start);
        if (p == M.end()) return false;

        auto n_next = p->second.size();
        while (n_next--) {
            auto to = M[start].back();
            M[start].pop_back();
            ans.push_back(to);

            if (recursive(to)) { return true; }

            ans.pop_back();
            M[start].push_front(to);
        }
        return false;
    }
    vector<string> findItinerary(const vector<vector<string>>& tickets) {
        M.clear(); n = tickets.size() + 1;
        for (const auto& v: tickets) {
            M[v[0]].push_back(v[1]);
        }
        for (auto& [k, v]: M) {
            sort(v.begin(), v.end(), greater<string>());
        }
        
        string start = "JFK";
        ans = {start};

        recursive(start);

        return ans;
    }
};

class Solution2 {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> M;

    vector<string> stk;

    void dfs(const string& curr) {
        // 看成欧拉路径的求解问题
        // 只需注意到如果起点的入度与出度不同（差1），则终点唯一且必定是 dfs 第一个完成回溯的点
        // 因此对普通邻结点，按照从小到大的顺序访问即可
        // 终结点找到并入栈后，之后这些邻结点会按照从大到小的顺序入栈。因此逆序输出即可
        while (M.count(curr) && M[curr].size() > 0) {
            string tmp = M[curr].top();
            M[curr].pop();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector<string> findItinerary(const vector<vector<string>>& tickets) {
        for (auto& it : tickets) {
            M[it[0]].emplace(it[1]);
        }
        dfs("JFK");

        reverse(stk.begin(), stk.end());
        return stk;
    }
};

class Solution {
public:
    unordered_map<string, vector<string>> M;

    vector<string> stk;

    void dfs(const string& curr) {
        // 看成欧拉路径的求解问题
        // 只需注意到如果起点的入度与出度不同（差1），则终点唯一且必定是 dfs 第一个完成回溯的点
        // 因此对普通邻结点，按照从小到大的顺序访问即可
        // 终结点找到并入栈后，之后这些邻结点会按照从大到小的顺序入栈。因此逆序输出即可
        while (M.count(curr) && M[curr].size() > 0) {
            string tmp = M[curr].back();
            M[curr].pop_back();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector<string> findItinerary(const vector<vector<string>>& tickets) {
        for (auto& v : tickets) {
            M[v[0]].emplace_back(v[1]);
        }
        
        for (auto& [k, v]: M) {
            sort(v.begin(), v.end(), greater<string>());
        }
        dfs("JFK");

        return vector<string>(stk.rbegin(), stk.rend());
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.findItinerary( {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}} );
    // cout << sol.findItinerary( {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}} );
    cout << sol.findItinerary( {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}, {"JFK","ABC"},{"ABC","JFK"}} );
    return 0;
}
