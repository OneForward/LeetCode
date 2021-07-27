/*
leet168


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    string convertToTitle(int f) {
        // 0ms
        string s;
        while (f) {
            s.push_back((f-1) % 26 + 'A'); f = (f-1) / 26;
        };
        return string(s.rbegin(), s.rend());
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.convertToTitle(701) << endl;
    for (int f = 1; f < 55; ++f)
        cout << f << ": " << sol.convertToTitle(f) << endl;
    return 0;
}
