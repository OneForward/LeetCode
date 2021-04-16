/*
lcci01.04


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
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> M;
        for (const auto& si: s) M[si]++;
        
        auto ok = true;
        for (const auto& [k, v]: M) {
            if (v % 2)  {
                if (ok) ok = false;
                else return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.canPermutePalindrome("aaabbb") << endl;
    return 0;
}
