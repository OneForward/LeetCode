/*
leet165


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

vector<int> split(const string& s, const string& delim = ".") {
    vector<int> v;

    string::size_type lastPos = s.find_first_not_of(delim, 0);
    string::size_type pos = s.find_first_of(delim, lastPos);
    while (string::npos != pos || string::npos != lastPos) {
        v.emplace_back(stoi(s.substr(lastPos, pos - lastPos)));
        lastPos = s.find_first_not_of(delim, pos);
        pos = s.find_first_of(delim, lastPos);
    }
    return v;
}

class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = split(version1), v2 = split(version2);
        auto p1 = v1.begin(), p2 = v2.begin();
        while (p1 != v1.end() && p2 != v2.end()) {
            if (*p1 < *p2) return -1;
            else if (*p1 > *p2) return 1;
            else p1++, p2++;
        }
        while (p1 != v1.end())  {
            if (*p1) return 1;
            p1++;
        }
        while (p2 != v2.end())  {
            if (*p2) return -1;
            p2++;
        }
        return 0;
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.compareVersion("0.1", "1.1") << endl;
    cout << sol.compareVersion("1.0.1", "1") << endl;
    cout << sol.compareVersion("1.0.1", "1.0.0001") << endl;
    cout << sol.compareVersion("1.0.0", "1") << endl;

    return 0;
}
