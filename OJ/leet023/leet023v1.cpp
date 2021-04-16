/*
leet023


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x=0) : val(x), next(NULL) {}
};

ListNode* from(vector<int>&& v) {
    ListNode* head {new ListNode(0)};
    ListNode* p = head;
    for (auto vi: v) {
        p->next = new ListNode(vi);
        p = p->next;
    }
    return head->next;
}

void disp(ListNode* p) {
    while (p)
    {
        printf("%d -> ", p->val); p = p->next;
    }
    printf("nullptr\n");
}



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& vec) {
        // O(N log K )
        auto cmp = [] (ListNode* p1, ListNode* p2) 
            { return p1->val > p2->val; };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> Q(cmp);
        for (auto vi: vec) Q.push( vi );
        
        
        ListNode head, *curr = &head;
        while (!Q.empty()) {
            auto p = Q.top(); Q.pop(); 
            curr->next = p; curr = curr->next;
            if (p->next) Q.push(p->next);
        }
        return head.next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* l1 = from({1, 4, 5}); disp(l1);
    ListNode* l2 = from({1, 3, 4}); disp(l2);
    ListNode* l3 = from({2, 6}); disp(l3);

    vector<ListNode*> vec = {l1, l2, l3};
    
    Solution sol;
    ListNode* ans = sol.mergeKLists(vec); disp(ans);

    return 0;
}
