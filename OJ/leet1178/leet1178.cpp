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
        // O(64*6*P), 152ms, 95%
        // 位运算，哈希
        // 将 每一个 word 保存为 bit-mask, 对每一个 7字母puzzle 的 64 种可能的 sub-mask 进行搜索即可
        int W = words.size(), P = puzzles.size();
        unordered_map<int, int> M;
        for (const auto& word: words) {
            auto key = 0;
            for (const auto& ch: word) {
                key |= 1 << (ch - 'a');
            }
            M[key]++;
        }


        vector<int> ans; ans.reserve(P);
        for (const auto& puzzle: puzzles) {
            auto cnt = 0; 
            for (size_t mask = 0; mask < 64; mask++)
            {
                auto key = 1 << (puzzle[0] - 'a');
                for (size_t i = 1; i < 7; i++)
                {
                    if (mask & (1 << (i-1))) key |= 1 << (puzzle[i] - 'a');
                }
                if (M.count(key)) cnt += M[key];
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
