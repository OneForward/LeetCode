/*
leet214


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
#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {

    vector<int> p;
    
    void Manacher(const string& s) {
        // Manacher 算法
        // Time O(n), Space O(n)
        vector<char> v = {'$', '.'};
        for (const auto ch: s) {
            v.push_back(ch);
            v.push_back('.'); 
        }
        v.push_back('%');

        string snew(v.begin(), v.end());
        p.clear(); p.resize(snew.size());

        // https://www.zhihu.com/question/37289584/answer/465656849
        // C 表示回文串的中心，用 R 表示回文串的右边半径坐标，
        // 所以 R = C + P[ C ] 。
        // C 和 R 所对应的回文串是当前循环中 R 最靠右的回文串
        // p[i] 储存 snew 中以 i 为中心的回文串的 左右臂长, 不含 i 本身
        // 而 start = (i - p[i]) / 2, len = p[i] 恰好就是该回文串在 s 中的对应位置
        int C = 0, R = 0;
        for (int i = 1; i < snew.size()-1; ++i) { 
            if (i < R) {
                p[i] = min(p[2*C-i], R-i);
            }
            while ( snew[i-p[i]-1] == snew[i+p[i]+1] ) p[i]++;
            if (i + p[i] > R) {
                R = i + p[i];
                C = i;
            }
        }
        // cout << p;
    }

public:
    string shortestPalindrome(string s) {
        // Time O(N), Space O(N)
        // O(N) 的 Manacher 预处理加上 N 次每次 O(1) 的回文串判断
        Manacher(s);
        int len = 0;
        for (int i = 0; i < p.size(); ++i) { 
            if ((i - p[i]) / 2 == 0) {
                len = max(len, p[i]);
            }
        }
        return string(s.rbegin(), s.rbegin() + s.size() - len ) + s;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.shortestPalindrome("aacecaaa") << endl;
    cout << sol.shortestPalindrome("abcd") << endl;
    return 0;
}
