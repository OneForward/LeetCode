/*
leet125


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
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (auto si: s) {
            if (isalnum(si)) {
                sgood += tolower(si);
            }
        }
        string sgood_rev(sgood.rbegin(), sgood.rend());
        return sgood == sgood_rev;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;

    return 0;
}
