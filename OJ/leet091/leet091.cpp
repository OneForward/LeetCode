/*
leet091


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

class Solution1 {
public:
    int numDecodings(string& s, int start) {
        if (start >= s.size()) return 1;

        int f1 = 0, f2 = 0;
        if ( s[start] - '0' > 0 ) f1 = numDecodings(s, start+1);
        if (start < s.size() - 1 ) {
            int x = (s[start] - '0') * 10 + s[start+1] - '0';
            if (x >= 10 && x <= 26) f2 = numDecodings(s, start+2); 
        }

        return f1 + f2;
        
    }
    int numDecodings(string s) {
        return numDecodings(s, 0);
    }
};

class Solution {
public:
    int numDecodings(string s) {
        // 0ms
        vector<int> ans(s.size() + 1);
        if (s.back() > '0') ans[s.size()-1] = 1; ans.back() = 1;
        for (int start = s.size() - 2; start >= 0; --start) {
            int f1 = 0, f2 = 0;
            if ( s[start] - '0' > 0 ) f1 = ans[start+1];
            int x = (s[start] - '0') * 10 + s[start+1] - '0';
            if (x >= 10 && x <= 26) f2 = ans[start+2];
            ans[start] = f1 + f2;
        }
        return ans[0];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.numDecodings("0") << endl;
    cout << sol.numDecodings("01") << endl;
    cout << sol.numDecodings("12") << endl;
    cout << sol.numDecodings("226") << endl;
    cout << sol.numDecodings("12232323") << endl;
    cout << sol.numDecodings("12232320184701200023753") << endl;
    return 0;
}
