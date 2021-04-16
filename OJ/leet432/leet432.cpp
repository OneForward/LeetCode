/*
leet432


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
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;





class AllOne {
public:
    // 哈希表 套 双端链表
    // 36ms, 98%, O(1)
    struct ListNode
    {
        string key;
        int val;
        ListNode* prev;
        ListNode* next;
    };
    unordered_map<string, ListNode*> M;
    ListNode* head, *tail;
    ListNode Head, Tail; 

    /** Initialize your data structure here. */
    AllOne() {
        head = &Head;  tail = &Tail;
        head->next = tail; tail->prev = head;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (M.count(key) == 0) {
            auto node = new ListNode{key, 1, tail->prev, tail};
            auto prev = tail->prev; prev->next = node;
            tail->prev = node; 
            M[key] = node;
            return;
        }

        auto node = M[key]; node->val++;
        auto prev = node->prev;
        while (prev != head and prev->val < node->val) {
            prev = prev->prev;
        }
        if (prev == node->prev) return;

        // delete 
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // insert
        auto next = prev->next;
        next->prev = node;
        prev->next = node;
        node->next = next;
        node->prev = prev;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (M.count(key) == 0) return;
        auto node = M[key]; node->val--;
        if (node->val == 0) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node; M.erase(key);
            return;
        }

        auto next = node->next;
        while (next != tail and next->val > node->val) {
            next = next->next;
        }
        if (next == node->next) return;

        // delete 
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // insert
        auto prev = next->prev;
        next->prev = node;
        prev->next = node;
        node->next = next;
        node->prev = prev;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return head->next->key;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return tail->prev->key;
    }
};



int main(int argc, char const *argv[])
{
    AllOne allone;
    allone.inc("x");
    allone.inc("x");
    allone.dec("x");
    cout << allone.getMaxKey() << endl;
    cout << allone.getMinKey() << endl;
    return 0;
}
