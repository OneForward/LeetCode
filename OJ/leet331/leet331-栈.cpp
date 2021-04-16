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
        // 栈 O(N)
        if (s.back() != '#') return false;

        vector<int> v = {1}; int n = s.size(); 
        for (int i = 0; i < n; i++)
        {
            if (v.empty()) return false;
            switch (s[i])
            {
            case ',': break;
            case '#': v.back()--; if (v.back() == 0) v.pop_back(); break;
            default:
                while (i < n and s[i] != ',') {
                    i++;
                } i--;
                v.back()--; if (v.back() == 0) v.pop_back();
                v.push_back(2);
            }
        }
        return v.empty();
    }
};
class Solution {
public:
    bool isValidSerialization(string s) {
        // 栈 O(N) Space O(1)
        if (s.back() != '#') return false;

        int v = 1; int n = s.size(); 
        for (int i = 0; i < n; i++)
        {
            if (v == 0) return false;
            switch (s[i])
            {
            case ',': break;
            case '#': v--; break;
            default:
                while (i < n and s[i] != ',') {
                    i++;
                } i--;
                v++;
            }
        }
        return v == 0;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.isValidSerialization("9,9,9,9,9,9,9,9,#,9,#,#,9,#,9,#,#,#,9,9,#,9,#,#,9,#,9,#,#,9,9,9,#,9,#,#,9,#,#,9,#,#,9,9,9,9,9,#,#,#,9,9,#,9,9,9,9,#,#,#,#,9,#,9,9,#,#,#,9,#,#,9,9,9,#,#,9,9,#,#,9,9,#,#,#,9,#,9,9,9,9,#,#,#,#,9,#,#,9,9,9,#,9,#,#,9,9,9,#,#,9,#,#,9,9,#,9,#,9,9,#,#,#,9,#,#,9,9,#,9,#,#,9,#,#,9,9,9,#,#,#,9,9,9,9,#,9,#,#,9,#,#,9,9,#,9,#,#,9,9,#,#,9,#,#,#,9,9,9,#,#,9,#,#,9,9,9,#,#,9,9,#,#,#,9,#,9,#,9,#,#") << endl;
    cout << sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << sol.isValidSerialization("1,#") << endl;
    cout << sol.isValidSerialization("9,#,#,1") << endl;
    return 0;
}
