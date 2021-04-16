/*
leet142


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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return {};

        auto A = head, B = head;
        do {
            A = A->next; B = B->next;
            if (B == nullptr) return {};
            B = B->next;
        } while (B and A != B);
        if (B == nullptr) return {};

        auto C = head; 
        while (C and C != A) {
            C = C->next; A = A->next;
        }
        return C;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    auto L = toList( {3,2,0,-4} , 1);
    disp(L, 1);
    disp(sol.detectCycle( L ), 0);
    return 0;
}
