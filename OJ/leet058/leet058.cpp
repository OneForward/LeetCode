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
        int N = s.size();
        int p = N - 1, len = 0;
        while (p >= 0 and s[p] == ' ') --p;
        while (p >= 0 and s[p] != ' ') --p, ++len;
        return len;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.lengthOfLastWord("") << endl;
    cout << sol.lengthOfLastWord(" ") << endl;
    cout << sol.lengthOfLastWord("   ") << endl;
    cout << sol.lengthOfLastWord("   word") << endl;
    cout << sol.lengthOfLastWord("   word ") << endl;

    return 0;
}
