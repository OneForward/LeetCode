/*
leet414


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

class Solution {
public:
    int thirdMax(const vector<int>& nums) {
        unordered_set<int> S;
        for (auto x: nums){ S.insert(x); if (S.size() > 2) break; }
        if (S.size() <= 2) return *max_element(S.begin(), S.end());
        
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        for (auto x: nums) {
            if (x == first || x == second || x == third ) continue;
            if (x > first) third = second, second = first, first = x;
            else if (x > second) third = second, second = x;
            else if (x > third) third = x;
        }
        return third;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.thirdMax({1,1,2}) << endl;
    cout << sol.thirdMax({3,2,1}) << endl;
    cout << sol.thirdMax({1,2}) << endl;
    cout << sol.thirdMax({2,2,3,1}) << endl;
    return 0;
}
