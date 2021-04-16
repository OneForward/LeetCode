/*
leet1178


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
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(const vector<string>& words, const vector<string>& puzzles) {
        // O(128 P), 152ms, 95%
        // 位运算，哈希
        // 将 每一个 word 保存为 bit-mask, 对每一个 7字母puzzle 的 64 种可能的 sub-mask 进行搜索即可
        int W = words.size(), P = puzzles.size();
        unordered_map<int, int> M;
        for (const auto& word: words) {
            auto x = 0;
            for (const auto& ch: word) {
                x |= 1 << (ch - 'a');
            }
            M[x]++;
        }


        vector<int> ans; ans.reserve(P);
        for (const auto& puzzle: puzzles) {
            auto x = 0, cnt = 0;
            for (const auto& ch: puzzle) {
                x |= 1 << (ch - 'a');
            }
            auto first = 1 << (puzzle[0] - 'a');
            auto mask = x;
            while (x) {
                if (x & first and M.find(x) != M.end()) cnt += M[x];
                x = (x - 1) & mask;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findNumOfValidWords({"aaaa","asas","able","ability","actt","actor","access"},
                        {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"}) << endl;
    return 0;
}
