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

        auto trans = [&](int pos, char ch) {
            switch (pos)
            {
            case 0: 
                if (issign(ch)) return 1;
                if (isdigit(ch)) return 2;
                if (isdot(ch)) return 3;
                return -1;
            
            case 1: 
                if (isdigit(ch)) return 2;
                if (isdot(ch)) return 3;
                return -1;
            
            case 2: 
                if (isdigit(ch)) return 2;
                if (isdot(ch)) return 4;
                if (isexp(ch)) return 6;
                return -1;

            case 3: 
                if (isdigit(ch)) return 5;
                return -1;
            
            case 4: 
                if (isdigit(ch)) return 5;
                if (isexp(ch)) return 6;
                return -1;
            
            case 5: 
                if (isdigit(ch)) return 5;
                if (isexp(ch)) return 6;
                return -1;
            
            case 6: 
                if (issign(ch)) return 7;
                if (isdigit(ch)) return 8;
                return -1;
            
            case 7: 
                if (isdigit(ch)) return 8;
                return -1;
            
            default:
                if (isdigit(ch)) return 8;
                return -1;
            }
        };
        
        int state = 0;
        for (auto&& ch: s) {
            state = trans(state, ch);
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
