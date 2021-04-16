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
        // Floyd 快慢算法
        auto A = head, B = head; // A fast, B slow
        while (A) {
            if (A->next == nullptr) break;
            A = A->next->next; B = B->next;
            
            if (A == B) {
                A = head;
                while (A != B) {
                    A = A->next; B = B->next;
                }
                return A;
            }
        }

        return nullptr;
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
