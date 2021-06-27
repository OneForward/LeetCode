/*
leet460


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;


struct Node
{
    int key, val, cnt;
    Node* prev, *next;
};

struct List
{
    Node Head{}, Tail{};
    Node* head, *tail;
    int len;

    List():head{&Head}, tail{&Tail}, len(0) {
        Head.next = &Tail; Tail.prev = &Head;
    }

    Node* push(int key, int val) {
        auto node = new Node{key, val, 0, tail->prev, tail};
        tail->prev->next = node; tail->prev = node;
        inc(node); len++;
        return node;
    }

    int inc(Node* node) {
        // inc counter of key, move it forward
        node->cnt++; 
        auto prev = node->prev;
        while (prev != head and prev->cnt <= node->cnt) {
            prev = prev->prev;
        }
        if (prev == node->prev) return node->val;

        // delete 
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // insert
        auto next = prev->next;
        next->prev = node;
        prev->next = node;
        node->next = next;
        node->prev = prev;

        return node->val;
    }

    int pop() {
        auto node = tail->prev; auto key = node->key;
        auto nodeprev = node->prev;
        nodeprev->next = tail; tail->prev = nodeprev;
        delete node; len--;
        return key;
    }
};

class LFUCache {
public:
    // 哈希表 套 双端链表
    // 36ms, 98%, O(1)

    unordered_map<int, Node*> M;
    List L;
    int N;

    LFUCache(int capacity):  N{capacity}  { }
    
    int get(int key) {
        if (M.find(key) == M.end()) return -1;

        return L.inc( M[key] );
    }
    
    void put(int key, int val) {
        if (N == 0) return;

        if (M.find(key) == M.end()) {
            // remove the minimum
            if (L.len == N) M.erase(L.pop());
            M[key] = L.push(key, val); 
            return;
        }
        
        // inc counter of key, move it forward
        M[key]->val = val;
        L.inc( M[key] );
    }


};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char const *argv[])
{
    // LFUCache lFUCache = LFUCache(2);
    // lFUCache.put(1, 1);   // cache=[1,_], cnt(1)=1
    // lFUCache.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    // cout << endl << lFUCache.get(1);      // 返回 1
    //                     // cache=[1,2], cnt(2)=1, cnt(1)=2
    // lFUCache.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
    //                     // cache=[3,1], cnt(3)=1, cnt(1)=2
    // cout << endl << lFUCache.get(2);      // 返回 -1（未找到）
    // cout << endl << lFUCache.get(3);      // 返回 3
    //                     // cache=[3,1], cnt(3)=2, cnt(1)=2
    // lFUCache.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
    //                     // cache=[4,3], cnt(4)=1, cnt(3)=2
    // cout << endl << lFUCache.get(1);      // 返回 -1（未找到）
    // cout << endl << lFUCache.get(3);      // 返回 3
    //                     // cache=[3,4], cnt(4)=1, cnt(3)=3
    // cout << endl << lFUCache.get(4);      // 返回 4
    //                     // cache=[3,4], cnt(4)=2, cnt(3)=3
    
    LFUCache lFUCache = LFUCache(3);
    lFUCache.put(1, 1);   
    lFUCache.put(2, 2);   
    lFUCache.put(3, 3);   
    lFUCache.put(4, 4);   
    cout << endl << lFUCache.get(4);      // 返回 3
    cout << endl << lFUCache.get(3);      // 返回 3
    cout << endl << lFUCache.get(2);      // 返回 -1（未找到）
    cout << endl << lFUCache.get(1);      // 返回 -1（未找到）
                        // cache=[3,4], cnt(4)=1, cnt(3)=3
                        // cache=[3,4], cnt(4)=2, cnt(3)=3
    
    
    // LFUCache lFUCache = LFUCache(2);
    // lFUCache.put(3,1);
    // lFUCache.put(2,1);
    // lFUCache.put(2,2);
    // lFUCache.put(4,3);
    // cout << endl << lFUCache.get(2) << endl;
    return 0;
}
