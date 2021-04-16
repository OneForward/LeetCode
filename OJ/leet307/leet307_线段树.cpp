#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

/*
线段树
单点修改，区间索引
*/


struct Node
{
    int lft, rht;
    int data;
    int mark;

    Node(int l, int r): lft(l), rht(r), data(0), mark(0) { }
    void add_mark(int inc) {
        mark += inc;
    }

};

class NumArray {
public:
    Node** nodes;
    vector<int>* arr;

    NumArray(vector<int>& nums) {
        if (nums.size() == 0) return;
        arr = &nums;
        nodes = new Node*[nums.size() * 4] ();
        for (int i=0; i<nums.size()*4; ++i) nodes[i] = nullptr;

        build(1, 0, nums.size()-1);
        // for (int i=0; i<(*arr).size()*4; ++i) if (nodes[i]) printf("(%d)[%d, %d] = %d\n", i, nodes[i]->lft, nodes[i]->rht, nodes[i]->data);
    }
    
    void build(int nind, int vlft, int vrht) {
       if (nodes[nind] == nullptr) 
           nodes[nind] = new Node(vlft, vrht);
       Node* node = nodes[nind];
       if (vlft == vrht) {
           nodes[nind]->data = (*arr)[vlft];
           return;
       }

       int vmid = (vlft + vrht) / 2;
       build( nind*2, vlft, vmid);
       build( nind*2+1, vmid+1, vrht);
       nodes[nind]->data = nodes[nind*2]->data + nodes[nind*2+1]->data;
    }

    void updateNodes(int nind, int vind, int inc) {
        Node* node=  nodes[nind];
        if (node->lft > vind or node->rht < vind) return;
        if (node->lft == node->rht) {
            node->data += inc;
            return;
        }

        int vmid = (node->lft + node->rht) / 2;
        if (vind <= vmid) updateNodes(nind*2, vind, inc);
        else updateNodes(nind*2+1, vind, inc);
        node->data += inc;
    }

    void update(int i, int val) {
        updateNodes(1, i, val-(*arr)[i]);
        (*arr)[i] = val;
        // printf("updating arr[%d] = %d\n", i, val);
        // for (int i=0; i<(*arr).size()*4; ++i) if (nodes[i]) printf("(%d)[%d, %d] = %d\n", i, nodes[i]->lft, nodes[i]->rht, nodes[i]->data);
    }
    
    int sumRange(int nind, int vlft, int vrht) {
        Node* node = nodes[nind];
        if (node->rht < vlft or node->lft > vrht) return 0;
        if (node->lft >= vlft and node->rht <= vrht) 
            return node->data;

        int vmid = (node->lft + node->rht) / 2, ans = 0;
        if (vmid >= vlft) ans += sumRange(nind*2, vlft, vrht);
        if (vmid+1 <= vrht) ans += sumRange(nind*2+1, vlft, vrht);
        
        return ans;      
    }

    int sumRange(int vlft, int vrht) {
        return sumRange(1, vlft, vrht);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main(int argc, char const *argv[])
{
    freopen("1.in", "r", stdin);

    int size, K, lft, rht, type, ans;
    cin >> size;
    vector<int> nums(size, 0);
    for (int i=0; i<size; ++i) cin >> nums[i];
    
    // for (auto x: nums) printf("%d ", x);
    NumArray* obj = new NumArray(nums);
    cin >> K;
    while (K--) {
       scanf("%d %d %d", &type, &lft, &rht);
       // printf("%d %d %d\n", type, lft, rht);
       switch (type) {
           case 0: ans = obj->sumRange(lft,rht); printf("%d\n", ans); break;
           case 1: obj->update(lft, rht);
       }
    }

    // cout << ans;


    return 0;
        
}
