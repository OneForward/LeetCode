/*
leet030


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <utility>
using namespace std;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // 68ms, 75%
        int M = words.size(), N = s.size();
        if (M == 0 || N == 0) return {};

        unordered_map<string, int> D;
        for (auto &&word : words) D[word]++;

        vector<int> ans; 
        int len = words[0].size(), i = 0, cnt, lft, rht;
        if (N < len) return {};
        while (i < len) {
            cnt = 0; lft = rht = i;
            unordered_map<string, int> C;
            while (rht + len <= N)  {
                string sub = s.substr(rht, len);
                rht += len;
                if (D.find(sub) == D.end()) {
                    lft = rht; C.clear(); cnt = 0;
                }
                else {
                    C[sub]++;
                    cnt++;
                    while (C[sub] > D[sub]) {// 子串存在较多重复word, 移动lft到第一次去除重复word的地方
                        string lft_w = s.substr(lft, len);
                        lft += len;
                        C[lft_w] --;
                        cnt--;
                    }
                    if (cnt == M) ans.push_back(lft);
                }
            }
            i++;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    // string s = "";
    // vector<string> words = {};

    string s = "wordgoodgoodgoodbestword";
    // vector<string> words = {"word","good","best","word"};
    vector<string> words = {"word","good","best","good"};
    // string s = "aaa";
    // vector<string> words = {"a","a"};
    // string s = "barfoothefoobarman";
    // vector<string> words = {"foo","bar"};
    // string s = "barfoofoobarthefoobarman";
    // vector<string> words = {"bar","foo","the"};

    Solution sol;
    
    vector ans = sol.findSubstring(s, words);

    for (auto ai: ans) cout << ai << ", "; cout << endl;
    return 0;
}
