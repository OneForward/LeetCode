/*
leet382


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
#include <random>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x=0) : val(x), next(nullptr) {}
    ListNode(const vector<int>& vs, int pos = -1) {
        vector<int> v = vs;
        ListNode head;
        ListNode* p = &head, *curr = nullptr;
        for (int i = 0; i < v.size(); ++i) {
            p->next = new ListNode(v[i]);
            p = p->next; 
            if (i == pos) curr = p;
        }
        p->next = curr;
        *this = *head.next;
    }
};

ListNode* from(const vector<int>& vs, int pos = -1) {
    return new ListNode(vs, pos);
}

ostream& operator<<(ostream& os, ListNode* p) {
    while (p)
    {
        os << p->val << " -> "; p = p->next;
    }
    os << "nullptr" << endl;
    return os;
}

class Solution1 {
    ListNode* head;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution1(ListNode* h) : head(h) { }
    
    /** Returns a random node's value. */
    int getRandom() {
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(0.0, 1.0);
        auto p = head, ans = p; auto n = 0;
        while (p) {
            ++n;
            if (dis(gen) < 1. / n) {
                ans = p;
            }
            p = p->next;
        }
        return ans->val;
    }
};

class Solution {
    ListNode* head;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* h) : head(h) { }
    
    /** Returns a random node's value. */
    int getRandom() {
        // 经典的蓄水池抽样问题
        auto p = head, ans = p; auto n = 0;
        while (p) {
            ++n;
            if (rand() % n == 0) {
                ans = p;
            }
            p = p->next;
        }
        return ans->val;
    }
};

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}


int main(int argc, char const *argv[])
{
      
    auto L = from({1, 2, 3, 4, 5, 6} );
    Solution sol(L);
    vector<int> Counter(7, 0);
    for (int i = 0; i < 10000; ++i) { 
        Counter[sol.getRandom()]++;
    }
    cout << Counter;
    return 0;
}
