/*
leet025


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:


    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        ListNode Head(0, head); auto P = &Head;

        auto reverse = [&] (ListNode* P, ListNode* Q) {
            auto prev = P->next, curr = prev->next, next = curr->next;
            while (curr != Q) {
                curr->next = prev;
                prev = curr, curr = next; if (next) next = next->next;
            }
            P->next->next = Q; P->next = prev;
        };

        auto Q = P;
        while (true) {
            for (int i = 0; i < k; i++) if (Q) Q = Q->next; 
            if (not Q) break;
            auto Qnext = Q->next, Pnext = P->next;
            reverse(P, Qnext); P = Q = Pnext;
        }
        return Head.next;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.reverseKGroup( toList({1,2,3,4,5, 6}), 2 ) << endl;
    cout << sol.reverseKGroup( toList({1,2,3,4,5, 6}), 3 ) << endl;
    cout << sol.reverseKGroup( toList({1,2,3,4,5}), 2 ) << endl;
    cout << sol.reverseKGroup( toList({1,2,3,4,5}), 3 ) << endl;
    cout << sol.reverseKGroup( toList({1,2,3,4,5}), 1 ) << endl;
    cout << sol.reverseKGroup( toList({1,}), 1 ) << endl;
    return 0;
}
