/*
lcofII029


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

using Node = ListNode;
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        
        auto newNode = new Node{insertVal, head};
        if (head == nullptr) {
            newNode->next = newNode;
            return newNode;
        }
        auto p = head;
        if (p->next == head) {
            head->next = newNode;
            return head;
        }
        while ( p->next != head ) {
            auto pnext = p->next;
            if (p->val <= insertVal and insertVal <= pnext->val) { // ok
                p->next = newNode; newNode->next = pnext;
                return head;
            }
            if (p->val > pnext->val) { // 首尾点
                if (p->val < insertVal or insertVal <= pnext->val) {
                    p->next = newNode; newNode->next = pnext;
                    return head;
                }
            }
            p = pnext;
        }
        p->next = newNode; newNode->next = head;
        return head;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
