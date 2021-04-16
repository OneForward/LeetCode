/*
leet071


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

string join(const vector<string>& v, string delim = "/") {
    if (v.empty()) return "/";
    string s;
    for (auto &&vi : v)
    {
        s.push_back('/'); s += vi;
    }
    return s;
}

class Solution {
public:
    string simplifyPath(string path) {
        int i = 0, n = path.size();
        auto next = [&]() -> string {
            while (i < n and path[i] == '/') i++;
            if (i == n) return {};
            int j = i;
            while (i < n and path[i] != '/') i++;
            return path.substr(j, i-j);
        };

        vector<string> v;
        while (true) {
            auto node = next();
            if (node == "") break;
            if (node == ".") continue;
            if (node == "..") { if (v.size()) v.pop_back(); continue; }
            v.push_back(node);
        }
        return join(v);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.simplifyPath("/home/") << endl;
    cout << sol.simplifyPath("/../") << endl;
    cout << sol.simplifyPath("/home//foo/") << endl;
    cout << sol.simplifyPath("/a/./b/../../c/") << endl;
    return 0;
}
