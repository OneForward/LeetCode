/*
NC132
约瑟夫环问题

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

class Solution {
public:
 
    struct Node {
        int val; Node* next;  
    };
    int ysf(int N, int M) {
        auto head = new Node{N}, p = head;
        for (int i = N-1; i >= 1; --i) p = new Node{i, p};
        head->next = p; p = head;
        
        int len = N; 
        while (len > 1) { 
            for (int i = 0; i < (M - 1) % len; ++i) p = p->next;
            p->next = p->next->next;
            len--;
        }
        return p->val;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
