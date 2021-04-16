/*
leet306


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

string add(string_view x, string_view y)  {
    // big number addition
    vector<char> v;
    char carry = 0, val;
    auto xi = x.rbegin(), yi = y.rbegin();
    while ( xi != x.rend() && yi != y.rend() ) {
        val = *xi - '0' + *yi - '0' + carry; xi++; yi++;
        carry = val / 10;
        val %= 10;
        v.push_back(val + '0');
    }
    while ( xi != x.rend()  ) {
        val = *xi - '0' + carry; xi++; 
        carry = val / 10;
        val %= 10;
        v.push_back(val + '0');
    }
    while ( yi != y.rend()  ) {
        val = *yi - '0' + carry; yi++; 
        carry = val / 10;
        val %= 10;
        v.push_back(val + '0');
    }
    if (carry) v.push_back('1');
    return string(v.rbegin(), v.rend());
}


class Solution {
public:

    bool isAdditiveNumber(string_view num, string_view x, string_view y, size_t next) {
        if (next == num.size()) return true;
        if (next > num.size()) return false;
        auto z = add(x, y);
        if (z == num.substr(next, z.size())) {
            z = num.substr(next, z.size());
            next = next + z.size();
            return isAdditiveNumber( num, y, z, next );
        }
        return false;
    }
    bool isAdditiveNumber(string_view num) {
        // 0ms
        int n = num.size();
        for (size_t i = 1; i <= n / 2; ++i) {
            auto x = num.substr(0, i);
            for (size_t j = 1; j <= n / 2; ++j) {
                if ( i + j + max(i, j) > n) continue;
                if (j >= 2 && num[i] == '0') continue;
                auto y = num.substr(i, j);
                if (isAdditiveNumber(num, x, y, i+j)) return true;
            }
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;  
    // cout << boolalpha << sol.isAdditiveNumber( "112358" ) << endl;
    // cout << boolalpha << sol.isAdditiveNumber( "199100199" ) << endl;
    cout << boolalpha << sol.isAdditiveNumber( "199001200" ) << endl;
    // cout << add("1984", "98") << endl;
    // cout << add("1", "99") << endl;
    // cout << add("1", "9999") << endl;
    // cout << add("9999999", "9999") << endl;
    // cout << 9999999 + 9999 << endl;
    return 0;
}
