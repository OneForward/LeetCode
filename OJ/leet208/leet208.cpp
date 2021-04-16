/*
leet208

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

struct Node
{
    bool isleaf;
    vector<Node*> next;

    Node(bool isleaf=false): isleaf(isleaf), next(26, nullptr) {}
};


class Trie {
public:
    Node* root;
    /** Initialize your data structure here. */
    Trie(): root{new Node()} {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for (const auto& ch: word) {
            if (p->next[ch-'a'] == nullptr) 
                p->next[ch-'a'] = new Node();
            p = p->next[ch-'a'];
        }
        p->isleaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for (const auto& ch: word) {
            if (p->next[ch-'a'] == nullptr) 
                return false;
            p = p->next[ch-'a'];
        }
        return p->isleaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for (const auto& ch: prefix) {
            if (p->next[ch-'a'] == nullptr) 
                return false;
            p = p->next[ch-'a'];
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    cout << boolalpha;

    Trie* tree = new Trie();
    tree->insert("apple");
    cout << tree->search("apple") << endl;
    cout << tree->search("app") << endl;
    cout << tree->startsWith("app") << endl;

    tree->insert("app");
    cout << tree->search("app") << endl;

    return 0;
}
