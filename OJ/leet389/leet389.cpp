/*
leet389


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

class Solution {
public:
    char findTheDifference(string s, string t) {
        // 异或运算 Time (n+m) Space O(1)
        char ans = 0;
        for (auto ch: s) ans ^= ch;
        for (auto ch: t) ans ^= ch;
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findTheDifference("abcd", "abcde") << endl;
    cout << sol.findTheDifference("a", "aa") << endl;
    return 0;
}
