/*
    给定孩子兄弟表示法表示的树, 求先序、后序、层次遍历
    [二叉树]
*/

#include <iostream>
#include <cstdio>

const int MAX_N = 100005;

using namespace std;

struct Queue
{
    int Q[MAX_N], qlft = 0, qrht=0;

    Queue() {}

    void push(int x) {
        qrht++; qrht %= MAX_N;
        Q[qrht] = x;
    }

    int pop() {
        qlft++; qlft %= MAX_N;
        return Q[qlft];
    }

    bool isempty() { return qlft == qrht; }
};

struct BTNode
{
    int weight;
    int lchild;
    int rchild;
    int parent;
    BTNode():weight(0), lchild(0), rchild(0), parent(0) {}
};

struct BTree
{
    BTNode tree[MAX_N];
    int root;

    void insert(int i, int l, int r, int w) {
        tree[i].weight = w;
        if (l) tree[i].lchild = l, tree[l].parent = i;
        if (r) tree[i].rchild = r, tree[r].parent = i;
    }

    void updateRoot() { root = 1; while (tree[root].parent) root++; }

    void preorder() { preorder(root); printf("\n"); }
    void preorder(int p) {
        printf("%d ", tree[p].weight);

        int lchild = tree[p].lchild;
        if (lchild) preorder(lchild);
        int child = tree[lchild].rchild;
        while (child) preorder(child), child = tree[child].rchild;
    }

    void postorder() { postorder(root); printf("\n"); }
    void postorder(int p) {
        int lchild = tree[p].lchild;
        if (lchild) postorder(lchild);
        int child = tree[lchild].rchild;
        while (child) postorder(child), child = tree[child].rchild;


        printf("%d ", tree[p].weight);
    }

    void bfs() {
        Queue Q;
        Q.push(root);

        while (not Q.isempty()) {
            int p = Q.pop();
            printf("%d ", tree[p].weight);

            int lchild = tree[p].lchild;
            if (lchild) Q.push(lchild);
            int child = tree[lchild].rchild;
            while (child) Q.push(child), child = tree[child].rchild;
        }
    }
};

BTree tree;
int N, l, r, w;

int main(int argc, char const *argv[])
{
    #ifdef DEBUG
    freopen("sjtu1214/1.in", "r", stdin);
    #endif
    cin >> N;
    for (int i=1; i<=N; ++i) {
        scanf(" %d %d %d ", &l, &r, &w);
        tree.insert(i, l, r, w);
    }

    tree.updateRoot();

    tree.preorder();
    tree.postorder();
    tree.bfs();

    return 0;
}
