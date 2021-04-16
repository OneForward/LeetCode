/*
leet093


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

int str2int(const string& s, int i, int j) {
    int ans = 0;
    for (int k = j; k >= i; --k) {
        ans *= 10;
        ans += s[k] - '0';
    }
    return ans;
}
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    auto ans = sol.restoreIpAddresses("25525511135");
    for (auto s: ans) {
        cout << s << endl;
    }
    return 0;
}
