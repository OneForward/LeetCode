/*
leet030


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;



class Solution {
public:
    vector<int> findSubstring(string s, const vector<string>& words) {
        // 字典树
        unordered_map<string, int> M;
        for (auto &&word : words) M[word]++;
        auto len = words[0].size(), N = words.size();
        vector<int> ans;

        function<bool(int, int)> f = [&] (int start, int cnt) ->bool {
            if (cnt == N) 
                return true;
            if (start + (N - cnt) * len > s.size()) return false;
            for (int i = start; i < s.size(); i++)
            {
                auto word = s.substr(i, len);
                if (M.find(word) != M.end() and M[word] > 0) {
                    M[word]--; 
                    auto ok = f(i+len, cnt+1);
                    M[word]++;
                    if (ok) return ok;
                    else break;
                } 
                else break;
            }
            return false;
        };

        for (int i = 0; i < s.size(); i++)
        {
            if (f(i, 0)) ans.push_back(i);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.findSubstring( "barfoothefoobarman", {"foo","bar"} ) << endl;
    // cout << sol.findSubstring( "wordgoodgoodgoodbestword", {"word","good","best","word"} ) << endl;
    // cout << sol.findSubstring( "wordgoodgoodgoodbestword", {"word","good","best","good"} ) << endl;
    cout << sol.findSubstring( "bcabbcaabbccacacbabccacaababcbb", {"c","b","a","c","a","a","a","b","c"}) << endl;
    return 0;
}
