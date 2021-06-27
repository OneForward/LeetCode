/*
leet705


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;


// 完全按照算法导论-开放哈希表-章节书写 chap11.4 p152 
// 开哈希表不支持删除
const int M = 10007;

int h1(int x) { return x % M;  }
int h2(int x)  { return 1 + x % (M-1);  }
int h(int x, int i) { return (h1(x) + i * h2(x) ) % M; }

class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> L;
    MyHashSet() : L(M) { }
    
    void add(int x) {
        for (int i = 0; i < M; i++)
        {
            auto hx = h(x, i);
            if (L[hx] == 0) L[hx] = x;
            if (L[hx] == x) break; // found
        }
        // full
    }

    
    /** Returns true if this set contains the specified element */
    bool contains(int x) {
        for (int i = 0; i < M; i++)
        {
            auto hx = h(x, i);
            if (L[hx] == x) return true;
            if (L[hx] == 0) return false; // removed or not found
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


int main(int argc, char const *argv[])
{
    
    return 0;
}
