/*
leet405


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    string toHex(unsigned int x) {
        vector<char> v;
        do {
            char digit = x & 0xf;
            if (digit < 10) digit += '0';
            else digit += 'a' - 10;
            v.push_back(digit);

            x >>= 4;
        } while(x);
        return string(v.rbegin(), v.rend());
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.toHex(0) << endl;
    cout << sol.toHex(26) << endl;
    cout << sol.toHex(-1) << endl;
    return 0;
}
