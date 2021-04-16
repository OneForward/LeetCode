/*
leet166


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <string>
#include <cassert>
#include <utility>
using namespace std;

int sign(int x) {
    return (x > 0) - (x < 0);
}

class Solution {
public:
    string fractionToDecimal(long long a, long long b) {
        // 0ms
        int isneg = sign(a) * sign(b);
        a = abs(a); b = abs(b);
        auto s = to_string(a/b);
        vector<int> v;  
        if (isneg == -1) v.push_back('-');
        v.insert(v.end(), s.begin(), s.end());  a %= b;
        if (a) v.push_back('.');
        
        unordered_map<int, int> S; int pos = v.size();
        while (true) {
            if (a == 0 || S.find(a) != S.end()) break;
            else S[a] = pos++; 
            a *= 10; v.push_back(a / b + '0'); a %= b;
        }
        if (a) {
            v.insert(v.begin()+S[a], '(');
            v.push_back(')');
        }
        return string(v.begin(), v.end());
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.fractionToDecimal(7, -12) << endl;
    cout << sol.fractionToDecimal(-50, 8) << endl;
    // cout << sol.fractionToDecimal(4, 333) << endl;
    // cout << sol.fractionToDecimal(2, 6) << endl;
    // cout << sol.fractionToDecimal(4, 6) << endl;
    // cout << sol.fractionToDecimal(5, 6) << endl;
    // cout << sol.fractionToDecimal(15, 6) << endl;
    // cout << sol.fractionToDecimal(15, 7) << endl;
    // cout << sol.fractionToDecimal(955, 37) << endl;
    return 0;
}
