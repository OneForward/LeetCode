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

    int ladderLength(string beginWord, string endWord, const vector<string>& wordList) {
        // 44ms
        // 双向 BFS
        unordered_set<string> S(wordList.begin(), wordList.end());
        if (S.count(endWord) == 0) return 0;

        unordered_set<string> beginSet, endSet, tmp;
        int ans = 1;

        beginSet.insert(beginWord); endSet.insert(endWord);
        while (beginSet.size() and endSet.size()) {
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }

            ans++; tmp.clear();
            for (auto word: beginSet) {
                for (auto& wi: word) {
                    auto old = wi;
                    for (auto ch = 'a'; ch <= 'z'; ++ch) {
                        wi = ch;
                        if (endSet.find(word) != endSet.end()) return ans;
                        if (S.find(word) != S.end()) {
                            tmp.insert(word); S.erase(word);
                        }
                    }
                    wi = old;
                }
            }
            beginSet = tmp;
        }
        
        return 0;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.ladderLength("hit", "cog", {"hot","dot","dog","lot","log","cog"}) << endl;
    cout << sol.ladderLength("hit", "cog", {"hot","dot","dog","lot","log",}) << endl;
    cout << sol.ladderLength("hot", "dog", {"hot","dog",}) << endl;
    return 0;
}
