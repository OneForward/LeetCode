/*
leet086


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
    ListNode* partition(ListNode* head, int x) {
        ListNode root {0, head}, *p = &root, *q = &root;
        while (true) {
            while (q->next and q->next->val >= x) q = q->next;
            auto qnext = q->next;
            if (not qnext) break;
            if (p == q) p = q = qnext;
            else {
                auto pnext = p->next;
                p->next = qnext; 
                q->next = qnext->next;
                qnext->next = pnext; p = qnext;
            }
        }
        return root.next;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.partition( toList( {1,4,3,2,5,2} ), 3 ) << endl;
    return 0;
}
