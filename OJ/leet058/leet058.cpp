/*
leet058


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        // 0ms
        if (s.size() == 0) return 0;
        int p1 = 0, p2 = 0;
        for (int i = 0; i < s.size()-1; ++i) {
            if (s[i] == ' ' && s[i+1] != ' ') p1 = i+1;
            if (s[i] != ' ' && s[i+1] == ' ') p2 = i+1;
        }
        if (s[s.size()-1] != ' ')  p2 = s.size();
        return p2 - p1;
    }
};
int main(int argc, char const *argv[])
{
    string s = " ";
    Solution sol;
    cout << sol.lengthOfLastWord(s) << endl;

    return 0;
}
