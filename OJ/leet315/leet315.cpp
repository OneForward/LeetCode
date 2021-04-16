/*
 * Solution 1:  线段树，O(nlogn)，超时
 * Solution 2: 二叉搜索树
 * Solution 3: 归并排序寻找逆序对
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;


#define max(x, y) ((x)>(y))?(x):(y)

struct Node
{
    int lft, rht;
    int data;
    Node(int l, int r): lft(l), rht(r) {}
};

struct SegTree
{
    Node** nodes;
    vector<int>* arr;
    int MAX_SIZE;
    const int NINF = -0x7FFFFFFF;

    SegTree(vector<int>& A) {
        if (A.size() == 0) return;
        arr = &A; MAX_SIZE = A.size() << 2;
        nodes = new Node*[MAX_SIZE] ();
        build(1, 0, A.size()-1);
    }

    void build(int nind, int vlft, int vrht) {
        if (nodes[nind] == nullptr) 
            nodes[nind] = new Node(vlft, vrht);

        if (vlft == vrht) {
             nodes[nind]->data = (*arr)[vlft];
             return;
        }
        
        int mid = (vlft + vrht) / 2;
        build(nind*2, vlft, mid);
        build(nind*2+1, mid+1, vrht);
        nodes[nind]->data = max(nodes[nind*2]->data, nodes[nind*2+1]->data); 
    }

    int query(int nind, int vind) {
        Node* node = nodes[nind]; 
        if (node->rht <= vind) return 0;
        if (node->lft > vind and node->data < (*arr)[vind]) return node->rht - node->lft + 1;
        if (node->lft == node->rht) return 0;
        return query(nind*2, vind) + query(nind*2+1, vind);
    }

    int query(int vind) { return query(1, vind); }
};

class Solution1 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        SegTree tree(nums); vector<int> ans(nums.size());
        for (int i=0; i<nums.size(); ++i) {
            ans[i] = tree.query(i);
        }
        return ans;
    }
};

/*
Solution2: 二叉搜索树
*/


template <class T>
struct BSTree
{
    struct BNode
    {
        BNode* lchild;
        BNode* rchild;
        T data;
        int count;

        BNode( T d=T(), BNode* l=nullptr, BNode* r=nullptr)
            :lchild(l), rchild(r), data(d), count(1) {}

    };
    BNode* root;

    BSTree(): root(nullptr) {}

    void insert(BNode*& node, const T& val, int& rhtCount) {
        if (node == nullptr) { node = new BNode(val); return; }

        if (val <= node->data) node->count++, insert(node->lchild, val, rhtCount);
        else if (val > node->data) rhtCount += node->count, insert(node->rchild, val, rhtCount);
    }

    int insert(const T& val) {
        int rhtCount = 0;
        insert(root, val, rhtCount);
        return rhtCount;
    }


};


class Solution2 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        BSTree<int> tree; vector<int> ans(nums.size());
        for (int i=nums.size()-1; i>=0; --i) {
            ans[i] = tree.insert(nums[i]);
        }
        return ans;
    }
};


/*
 * Solution 3: 归并排序寻找逆序对
*/

class Solution {
public:
struct Node {
    int val;
    int ind;
    Node(int v, int i):val(v), ind(i) {}
};

void merge_sort(Node** nodes, int lo, int hi, Node** tmp, vector<int>& cnt) {
    if (hi <= lo) return;
    int mid = (lo + hi) / 2;
    merge_sort(nodes, lo, mid, tmp, cnt);
    merge_sort(nodes, mid+1, hi, tmp, cnt);

    int rht1 = lo, rht2 = mid+1, k = lo; 
    while (rht1 <= mid and rht2 <= hi) {
        while (rht1 <= mid and nodes[rht1]->val <= nodes[rht2]->val) tmp[k++] = nodes[rht1++], cnt[nodes[rht1-1]->ind] += rht2 - mid - 1;
        while (rht2 <= hi and nodes[rht1]->val > nodes[rht2]->val) tmp[k++] = nodes[rht2++];
    }
    while (rht1 <= mid) tmp[k++] = nodes[rht1++], cnt[nodes[rht1-1]->ind] += rht2 - mid - 1;
    while (rht2 <= hi) tmp[k++] = nodes[rht2++];
    for (int i=lo; i<=hi; ++i) nodes[i] = tmp[i];
}

    vector<int> countSmaller(vector<int>& nums) {
        Node** nodes = new Node*[nums.size()]();
        Node** tmp   = new Node*[nums.size()]();
        for (int i=0; i<nums.size(); ++i) 
            nodes[i] = new Node(nums[i], i);

        vector<int> cnt(nums.size(), 0);
        merge_sort(nodes, 0, nums.size()-1, tmp, cnt);
        return cnt;
    }
};




int main(int argc, char const *argv[])
{
    // freopen("leet315/1.in", "r", stdin);

    int size;
    cin >> size;

    vector<int> nums(size);
    for (int i=0; i<size; ++i) cin >> nums[i];
    for (auto x: nums) printf("%d ", x); printf("\n");

    Solution solution;
    vector<int> ans = solution.countSmaller(nums);
    for (auto x: ans) printf("%d ", x);

    return 0;
        
}
