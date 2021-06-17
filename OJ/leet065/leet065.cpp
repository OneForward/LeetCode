/*
leet065


*/


#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:

    bool isNumber(string s) {
        auto issign = [](char ch) { return ch == '+' or ch == '-'; };
        auto isdot = [](char ch) { return ch == '.'; };
        auto isexp = [](char ch) { return tolower(ch) == 'e'; };
        auto type = [&](char ch) {  
            if (issign(ch)) return 0;
            if (isdigit(ch)) return 1;
            if (isdot(ch)) return 2;
            if (isexp(ch)) return 3;
            return 4;
        };

        // +  0-9  .  e o.w
        int trans[][5] = {
            {1, 2, 3, -1, -1},
            {-1, 2, 3, -1, -1},
            {-1, 2, 4, 6, -1},
            {-1, 5, -1, -1, -1},
            {-1, 5, -1, 6, -1},
            {-1, 5, -1, 6, -1},
            {7, 8, -1, -1, -1},
            {-1, 8, -1, -1, -1},
            {-1, 8, -1, -1, -1},
        };

        int state = 0;
        for (auto&& ch: s) {
            state = trans[state][type(ch)];
            if (state == -1) break;
        }
        int ok[] = {2, 4, 5, 8};
        
        return any_of(ok, ok+4, [&](int last) { return last == state; });
    }
}; 


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.isNumber("0.12") << endl;
    cout << sol.isNumber(".") << endl;
    cout << sol.isNumber(".1") << endl;
    cout << sol.isNumber("e") << endl;
    return 0;
}
