/*
leet211

Trie

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

class WordDictionary {
    // 80ms
    bool isleaf = false;
    WordDictionary* next[26] {};

public:
    /** Initialize your data structure here. */
    WordDictionary() { }
    
    void addWord(string word) {
        auto p = this;
        for (const auto& ch: word) {
            if (p->next[ch-'a'] == nullptr) p->next[ch-'a'] = new WordDictionary();
            p = p->next[ch-'a'];
        }
        p->isleaf = true;
    }

    bool search(WordDictionary* p, const string& word, size_t start = 0) {
        if (p == nullptr) return false;

        for (; start < word.size(); start++)
        {
            auto ch = word[start];
            if (ch == '.') {
                for (auto pnext: p->next) {
                    if (search(pnext, word, start+1)) return true;
                }
                return false;
            }

            if (p->next[ch-'a'] == nullptr) return false;
            p = p->next[ch-'a'];
        }
        
        return p->isleaf;
    }

    bool search(const string& word) {
        return search(this, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


int main(int argc, char const *argv[])
{
    cout << boolalpha;

    auto wordDictionary =  WordDictionary();
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << wordDictionary.search("pad") << endl; // return False
    cout << wordDictionary.search("bad") << endl; // return True
    cout << wordDictionary.search(".ad") << endl; // return True
    cout << wordDictionary.search("b..") << endl; // return True


    return 0;
}
