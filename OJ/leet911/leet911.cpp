/*
leet911


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

struct Node
{
    int key, val, cnt;
    Node* prev, *next;
};

struct List
{
    Node Head{}, Tail{};
    Node* head, *tail;
    int len;

    List():head{&Head}, tail{&Tail}, len(0) {
        Head.next = &Tail; Tail.prev = &Head;
    }

    Node* push(int key, int val) {
        auto node = new Node{key, val, 0, tail->prev, tail};
        tail->prev->next = node; tail->prev = node;
        inc(node); len++;
        return node;
    }

    int inc(Node* node) {
        // inc counter of key, move it forward
        node->cnt++; 
        auto prev = node->prev;
        while (prev != head and prev->cnt <= node->cnt) {
            prev = prev->prev;
        }
        if (prev == node->prev) return node->val;

        // delete 
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // insert
        auto next = prev->next;
        next->prev = node;
        prev->next = node;
        node->next = next;
        node->prev = prev;

        return node->val;
    }

    int pop() {
        auto node = tail->prev; auto key = node->key;
        auto nodeprev = node->prev;
        nodeprev->next = tail; tail->prev = nodeprev;
        delete node; len--;
        return key;
    }
};

class LFUCache {
public:
    // 哈希表 套 双端链表
    // 36ms, 98%, O(1)

    unordered_map<int, Node*> M;
    List L;
    int N;

    LFUCache(int capacity):  N{capacity}  { }
    
    int get(int key) {
        if (M.find(key) == M.end()) return -1;

        return L.inc( M[key] );
    }
    
    void put(int key, int val) {
        if (N == 0) return;

        if (M.find(key) == M.end()) {
            // remove the minimum
            if (L.len == N) M.erase(L.pop());
            M[key] = L.push(key, val); 
            return;
        }
        
        // inc counter of key, move it forward
        M[key]->val = val;
        L.inc( M[key] );
    }


};


class TopVotedCandidate {
public:
    VI ans;
    VI timestamps;
    TopVotedCandidate(const vector<int>& persons, const vector<int>& times) {
        timestamps = times;

        using Pair = pair<int, int>; // vote, time
        Pair votes[5005]{};
        auto cmp = [&](const int& lft, const int& rht) {
            return votes[lft] < votes[rht];
        };
        auto Q = priority_queue<Pair>();
        ans.reserve(persons.size()+1); ans.push_back(0);
        int time = 0;
        for (auto&& x: persons) {

        }
        
        
    }
    
    int q(int t) {
        auto pos = lower_bound(ALL(timestamps), t) - timestamps.begin();
        return ans[pos];
    }
};



int main(int argc, char const *argv[])
{
    TopVotedCandidate topVotedCandidate =  TopVotedCandidate({0, 1, 1, 0, 0, 1, 0}, {0, 5, 10, 15, 20, 25, 30});
    cout << endl << topVotedCandidate.q(3); // 返回 0 ，在时刻 3 ，票数分布为 [0] ，编号为 0 的候选人领先。
    cout << endl << topVotedCandidate.q(12); // 返回 1 ，在时刻 12 ，票数分布为 [0,1,1] ，编号为 1 的候选人领先。
    cout << endl << topVotedCandidate.q(25); // 返回 1 ，在时刻 25 ，票数分布为 [0,1,1,0,0,1] ，编号为 1 的候选人领先。（在平局的情况下，1 是最近获得投票的候选人）。
    cout << endl << topVotedCandidate.q(15); // 返回 0
    cout << endl << topVotedCandidate.q(24); // 返回 0
    cout << endl << topVotedCandidate.q(8); // 返回 1

    return 0;
}
