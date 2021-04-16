/*
lcof45


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
    string minNumber(const vector<int>& A) {
        vector<string> v;
        for (auto&& x: A) v.push_back(to_string(x));

        auto cmp = [&](const string& x, const string& y) {
            return x + y < y + x;
        };
        
        sort(v.begin(), v.end(), cmp);
        string ans;
        for (auto&& x: v) ans += x;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minNumber({3,30,34,5,9}) << endl;
    return 0;
}
