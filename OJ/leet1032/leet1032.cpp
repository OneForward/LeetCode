/*
leet1032


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

struct Trie
{
    bool isleaf{};
    Trie* next[26]{};
};


class StreamChecker {
public:
    Trie trie;
    string s;
    StreamChecker(const vector<string>& words) {
        for (auto&& word: words) {
            auto root = &trie;
            for (int i = word.size() - 1; i >= 0; i--)
            {
                auto ch = word[i] - 'a';
                if (not root->next[ch]) root->next[ch] = new Trie;
                root = root->next[ch];
            }
            root->isleaf = true;
        }
    }
    
    bool query(char letter) {
        auto root = &trie;
        s.push_back(letter);
        for (int i = s.size() - 1; i >= 0; i--)
        {
            auto ch = s[i] - 'a';
            if (not root->next[ch]) break;
            root = root->next[ch];
            if (root->isleaf) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */


int main(int argc, char const *argv[])
{
    StreamChecker streamChecker = StreamChecker({"cd","f","kl"}); // 初始化字典
    cout << boolalpha;
    cout << endl << streamChecker.query('a');          // 返回 false
    cout << endl << streamChecker.query('b');          // 返回 false
    cout << endl << streamChecker.query('c');          // 返回 false
    cout << endl << streamChecker.query('d');          // 返回 true，因为 'cd' 在字词表中
    cout << endl << streamChecker.query('e');          // 返回 false
    cout << endl << streamChecker.query('f');          // 返回 true，因为 'f' 在字词表中
    cout << endl << streamChecker.query('g');          // 返回 false
    cout << endl << streamChecker.query('h');          // 返回 false
    cout << endl << streamChecker.query('i');          // 返回 false
    cout << endl << streamChecker.query('j');          // 返回 false
    cout << endl << streamChecker.query('k');          // 返回 false
    cout << endl << streamChecker.query('l');          // 返回 true，因为 'kl' 在字词表中。

    
    return 0;
}
