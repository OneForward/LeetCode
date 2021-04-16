/*
leet424
sliding window

*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // O(n) 
        // 题意本质是要求 [lft, rht]  中的非 max-freq 的字符的总数目 <= k
        // 因此，当 [lft, rht] 符合要求时，可以贪心扩张 rht，
        
        // f(l, r) 记录了 s[l, r] 中 non-max-freq 的个数，
        // g(l, r) 记录了 s[l, r] 中 max-freq 的个数
        // 算法本质: 若以 l 为左端点，右侧 r 最多能延伸到几何
        // 对于 r1, 满足 f(l, r1) = k, f(l, r1+1) = k + 1
        // 则 对任意 r1 < r2:  
        //   g(l, r2) - g(l, r1) <= r2 - r1
        // => r2 - f(l, r2) - r1 + f(l, r1) <= r2 - r1
        // => f(l, r2) >= f(l, r1) 
        // 因此 f(l, r2) >=  f(l, r1+1) = k + 1 恒成立


        // 最后，更新 maxCount 只需考虑新晋字符 s[rht] 即可，
        // 因为固定长度 len，每次向右滑动，如果 新晋字符 s[rht] 的频率没有达到 maxCount，
        // 则 max-feq < maxCount, 因此 non-max-freq > k 必成立
        int n = s.size(), ans = 0, lft = 0, maxCount = 0;
        vector<int> Counter(26);
        
        for (int rht = 0; rht < n; ++rht){ 
            Counter[s[rht]-'A']++; maxCount = max(maxCount, Counter[s[rht]-'A']);
            if (maxCount + k >= rht - lft + 1) {
                ans =  rht - lft + 1; 
                continue;
            }
            Counter[s[lft]-'A']--; lft++;  
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.characterReplacement("", 2) << endl;
    // cout << sol.characterReplacement("AAAA", 0) << endl;
    // cout << sol.characterReplacement("BAAA", 0) << endl;
    cout << sol.characterReplacement("BAAAB", 2) << endl;
    // cout << sol.characterReplacement("ABAA", 0) << endl;
    // cout << sol.characterReplacement("ABAB", 2) << endl;
    // cout << sol.characterReplacement("AABABBA", 1) << endl;
    return 0;
}
