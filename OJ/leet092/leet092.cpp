/*
leet092


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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode Head(0, head); auto prev = &Head;
        for (int i = 1; i < left; i++) prev = prev->next;
        auto P = prev, curr = prev->next, next = curr->next;
        for (int i = left; i < right; i++) {
            prev = curr; curr = next;
            next = next->next;
            curr->next = prev;
        }
        P->next->next = next;  P->next = curr;
        return Head.next;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.reverseBetween( toList( {1,2,3,4,5} ), 2, 4 ) << endl;
    cout << sol.reverseBetween( toList( {1,} ), 1, 1) << endl;
    return 0;
}
