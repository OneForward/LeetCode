/*
leet138


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList1(Node* head) {
        // hashed_map, O(N), O(N) extra for dict
        unordered_map<Node*, Node*> M;
        Node dummy(0); 
        auto prev = &dummy, p = head;
        while (p) {
            prev->next = new Node(p->val);
            prev = prev->next;
            M[p] = prev;
            p = p->next;
        }

        p = head;
        while (p) {
            M[p]->random = M[p->random];
            p = p->next;
        }
        return dummy.next;
    }

    Node* copyRandomList(Node* head) {
        // weavened list, O(N), O(1) extra
        if (head == nullptr) return nullptr;
        
        auto p = head;
        while (p) {
            auto pnext = p->next;
            p->next = new Node(p->val, pnext, nullptr);
            p = pnext;
        }

        p = head;
        while (p) {
            if (p->random) p->next->random = p->random->next;
            p = p->next->next;
        }

        p = head; auto p2 = p->next, head2 = p2;
        while (p) {
            p->next = p2->next;
            p = p->next;
            if (p == nullptr) break;
            p2->next = p->next;
            p2 = p2->next;
        }

        return head2;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   

    return 0;
}
