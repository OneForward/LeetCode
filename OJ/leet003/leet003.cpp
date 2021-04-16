#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        // 朴素的O(N) 做法，空间O(N)
        // f[i] 记录 s[0..=i] 的最长不含重复字符的字串长度
        // prev[i] 记录 s[i] 的上一次出现位置
        int prev[255] {}, ans = 0;
        vector<int> f(s.size()+1);
        f[0] = 0;
        
        for (int i = 0; i < s.size(); ++i) { 
            f[i+1] = min( f[i], i - prev[s[i]] ) + 1;
            prev[s[i]] = i + 1;
        }


        return *max_element(f.begin(), f.end());
    }

    int lengthOfLongestSubstring(string s) {
        // 8ms, 接下来优化空间即可, Time O(N) Space O(1)
        // f[i] 记录 s[0..=i] 的最长不含重复字符的字串长度
        // prev[i] 记录 s[i] 的上一次出现位置
        int prev[255] {}, f = 0, ans = 0;
        
        for (int i = 0; i < s.size(); ++i) { 
            f = min( f, i - prev[s[i]] ) + 1;
            prev[s[i]] = i + 1;
            ans = max(ans, f);
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{

    Solution solution;

    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << solution.lengthOfLongestSubstring("bbbbb") << endl;
    cout << solution.lengthOfLongestSubstring("pwwkew") << endl;

    return 0;
        
}
