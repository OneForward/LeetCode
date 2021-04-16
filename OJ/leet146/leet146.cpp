/*
leet146


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;



// 哈希表 + 双端链表
struct Node
{
    int key, val;
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
        auto node = new Node{key, val, tail->prev, tail};
        tail->prev->next = node; tail->prev = node;
        len++;
        return node;
    }
    void move_to_tail(Node* node) {
        if (node->next == tail) return;
        auto nodeprev = node->prev;
        auto nodenext = node->next;
        auto tailprev = tail->prev;
        nodeprev->next = nodenext;
        nodenext->prev = nodeprev;
        node->next = tail; node->prev = tailprev;
        tail->prev = node; tailprev->next = node;
    }
    int pop() {
        auto node = head->next;
        auto nodenext = node->next;
        head->next = nodenext;
        nodenext->prev = head;
        auto key = node->key;
        delete node; len--;
        return key;
    }
};


class LRUCache {
public:
    unordered_map<int, Node*> M;
    List L;
    int N;
    LRUCache(int capacity): N{capacity} {
    }
    
    int get(int key) {
        if (M.find(key) == M.end()) return -1;
        auto node = M[key];
        L.move_to_tail(node);
        return node->val;
    }
    
    void put(int key, int val) {
        if (M.find(key) != M.end()) { 
            auto node = M[key];
            node->val = val; 
            L.move_to_tail(node);
            return; 
        }

        M[key] = L.push(key, val);
        if (L.len > N) {
            M.erase(L.pop());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(int argc, char const *argv[])
{
    LRUCache lRUCache (1);
    lRUCache.put(2, 1); // 缓存是 {1=1}
    cout << endl << lRUCache.get(2);    // 返回 1
    lRUCache.put(3, 2); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << endl << lRUCache.get(2);    // 返回 -1 (未找到)
    cout << endl << lRUCache.get(3);    // 返回 -1 (未找到)
 
    LRUCache lRUCache (2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    cout << endl << lRUCache.get(1);    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << endl << lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << endl << lRUCache.get(1);    // 返回 -1 (未找到)
    cout << endl << lRUCache.get(3);    // 返回 3
    cout << endl << lRUCache.get(4);    // 返回 4
 
    return 0;
}
