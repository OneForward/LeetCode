/*
leet167


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> twoSum1(const vector<int>& v, int target) {
        // 16ms, 哈希法
        unordered_map<int, int> S;
        for (int i = 0; i < v.size(); ++i) S[v[i]] = i+1;
        for (int i = 0; i < v.size(); ++i) {
            auto p = S.find(target - v[i]);
            if (p != S.end()) {
                if (i < p->second) return {i+1, p->second};
                else return {p->second, i+1};
            }
        }
        return {};
    }
    vector<int> twoSum(const vector<int>& v, int target) {
        // 8ms, 双指针法
        int lft = 0, rht = v.size()-1;
        while (true) {
            int sum = v[lft] + v[rht];
            if (sum == target) return {lft+1, rht+1};
            else if (sum < target) lft++;
            else rht--;
        }
        return {};
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   

    auto ans = sol.twoSum({2,7,11,15}, 9);


    for (auto vi: ans) cout << vi << ", "; cout << endl;
    return 0;
}
