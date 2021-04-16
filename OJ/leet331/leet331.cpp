/*
leet331


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

class Solution {
public:
    bool isValidSerialization(string s) {
        stack<int> S; S.push(1);
        for (int i = 0; i < s.size(); i++)
        {
            if (S.empty()) return false;
            switch (s[i])
            {
            case ',': break;
            case '#':  S.top()--; if (S.top() == 0) S.pop(); break;
            default:
                while (isdigit(s[i])) i++; i--;
                S.top()--;  if (S.top() == 0) S.pop();
                S.push(2);
            }
        }
        return S.empty();
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.isValidSerialization("9,3,4,#,#,1,#,#,#,2,#,6,#,#") << endl;
    cout << sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << sol.isValidSerialization("1,#,#") << endl;
    cout << sol.isValidSerialization("1,#,#,#,#") << endl;
    cout << sol.isValidSerialization("#") << endl;
    cout << sol.isValidSerialization("9,#,#,1") << endl;
    cout << sol.isValidSerialization("1,#") << endl;
    return 0;
}
