/*
leet556


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
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.size();
        int j = len - 1;
        while (j > 0 and s[j-1] >= s[j]) j--;
        if (j == 0) return -1;
        j--; 

        int i = len - 1;
        while (s[j] >= s[i]) i--;
        swap(s[j], s[i]);

        int lft = j + 1, rht = len - 1;
        while (lft < rht) {
            swap(s[lft], s[rht]); lft++; rht--;
        }

        auto ans = stoll(s);
        return ans > INT_MAX ? -1 : ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.nextGreaterElement(12) << endl;
    cout << sol.nextGreaterElement(1234) << endl;
    cout << sol.nextGreaterElement(21) << endl;
    return 0;
}
