/*
leet677


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;



struct Trie {
    Trie* next[26]{};
    int sum{};
    bool isend{};
};


class MapSum {
public:
    Trie tree;

    MapSum() { }
    
    void insert(string key, int val) {
        auto root = &tree;
        
    }
    
    int sum(string prefix) {

    }
};



int main(int argc, char const *argv[])
{
    MapSum mapsum;
    mapsum.insert("apple", 3);
    cout << mapsum.sum("app") << endl;
    mapsum.insert("app", 2);
    cout << mapsum.sum("ap") << endl;
    return 0;
}
