/*
leet421


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
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;


struct Trie
{
    Trie* next[2]{};
};


class Solution {
public:

    int findMaximumXOR(const vector<int>& nums) {
        // 68ms, O(32 N)
        // 从最高位开始，逐位向低处检查
        Trie* trie = new Trie;

        int ans = 0;
        for (auto x: nums) {
            auto node = trie, cur_node = trie;
            auto one = 1 << 30, cur_xor = 0;
            while (one) {
                auto bit = (one & x) ? 1 : 0;
                if (node->next[bit] == nullptr) node->next[bit] = new Trie;
                node = node->next[bit];

                auto toggled_bit = 1 - bit;
                cur_xor <<= 1;
                if (cur_node->next[toggled_bit]) {
                    cur_node = cur_node->next[toggled_bit];
                    cur_xor |= 1;
                }
                else cur_node = cur_node->next[bit];
                one >>= 1;
            }
            ans = max(ans, cur_xor);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findMaximumXOR({3, 10, 5, 25, 2, 8}) << endl;
    cout << sol.findMaximumXOR({8, 10, 2}) << endl;
    return 0;
}
