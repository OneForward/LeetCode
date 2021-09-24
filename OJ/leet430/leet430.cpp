/*
leet430


*/

// #include "../utils/LeetCpp.utils.hpp"
#include <iostream>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* f(Node* p) {
        if (not p) return p;
        auto pnext = p->next;
        auto pchild = p->child;
        auto ret = p;
        p->child = nullptr;
        if (pchild) {
            p->next = pchild;
            pchild->prev = p;
            ret = f(pchild);
            if (pnext) {
                ret->next = pnext;
                pnext->prev = ret;
            }
        }
        if (pnext) {
            ret = f(pnext);
        }
        return ret;
    }
    
    Node* flatten(Node* head) {
        f(head);
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
