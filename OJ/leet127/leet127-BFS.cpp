/*
leet127


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
    int ladderLength(string beginWord, string endWord, vector<string> wordList) {
        // BFS
        unordered_set<string> S(wordList.begin(), wordList.end());
        if (S.count(endWord) == 0) return 0;

        queue<string> Q; Q.push(beginWord);
        int ans = 1;

        while (Q.size()) {
            auto len = Q.size();
            auto word = Q.front(); Q.pop();

            ans++; 
            while (len--) {
                for (auto& wi: word) {
                    auto old = wi;
                    for (auto ch = 'a'; ch <= 'z'; ++ch) {
                        wi = ch;
                        if (word == endWord) return ans;
                        if (S.find(word) != S.end()) {
                            Q.push(word); S.erase(word);
                        }
                    }
                    wi = old;
                }
            }
        }
        
        return 0;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.ladderLength("hit", "cog", {"hot","dot","dog","lot","log","cog"}) << endl;
    cout << sol.ladderLength("hit", "cog", {"hot","dot","dog","lot","log",}) << endl;
    return 0;
}
