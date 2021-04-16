/*
    集合
    操作: union / difference / intersection
    [Binary Search Tree(BST)]
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int N, M, x;
char op;

struct BSTNode
{
    int val;
    BSTNode* lchild;
    BSTNode* rchild;
    BSTNode(int v=0, BSTNode* l=nullptr, BSTNode* r=nullptr)
        : val(v), lchild(l), rchild(r) {}
};

struct BSTree
{
    BSTNode* root;

    BSTree() { root = nullptr; }
    ~BSTree() { clear(); }
    void insert(int x) { insert(root, x); }

    void insert(BSTNode*& p, int x) {
        if (p == nullptr) { p = new BSTNode(x); return; }
        if (x < p->val) insert(p->lchild, x);
        else if (x > p->val) insert(p->rchild, x);
    }

    void inorder() { inorder(root); }

    void inorder(BSTNode* p) {
        if (p == nullptr) return;

        inorder( p->lchild );
        printf("%d ", p->val);
        inorder( p->rchild );
    }

    void clear() { clear(root); }

    void clear(BSTNode*& p) {
        if (p == nullptr) return;

        if (p->lchild) clear(p->lchild);
        if (p->rchild) clear(p->rchild);
        delete p; p = nullptr;
    }

    BSTNode* find(BSTNode* p, int x) {
        if (p == nullptr) return nullptr;

        if (x < p->val) return find(p->lchild, x);
        else if (x > p->val) return find(p->rchild, x);
        else return p;
    }

    BSTNode* find(int x) { return find(root, x); }

    void remove(int x) { return remove(root, x); }

    void remove(BSTNode*& p, int x) {
        if (p == nullptr) return;
        if (x < p->val) remove(p->lchild, x);
        else if (x > p->val) remove(p->rchild, x);
        else {
            BSTNode* delNode = p, *delNodeParent = p;
            if (p->lchild and p->rchild) {
                delNode = p->rchild;
                while (delNode and delNode->lchild)
                    delNodeParent = delNode, delNode = delNode->lchild;
                p->val = delNode->val;
                if (p == delNodeParent) p->rchild = delNode->rchild;
                else delNodeParent->lchild = delNode->rchild;
            }
            else if (p->lchild or p->rchild){
                if (p->lchild) delNode = p->lchild;
                else if (p->rchild) delNode = p->rchild;
                if (delNode) p->val = delNode->val, 
                             p->lchild = delNode->lchild, 
                             p->rchild = delNode->rchild;
            }
            else p = nullptr;

            if (delNode == root) root = nullptr;
            delete delNode; delNode = nullptr;
        }
    }
};

BSTree* A = new BSTree(), *B = new BSTree();


int main(int argc, char const *argv[])
{
    #ifdef DEBUG
    freopen("sjtu1218/2.in", "r", stdin);
    #endif

    cin >> N;
    while (N--) {
        scanf(" %c %d ", &op, &M);
        switch (op) {
            case '+': while (M--) scanf(" %d ", &x), A->insert(x); A->inorder(); break;
            case '-': while (M--) scanf(" %d ", &x), A->remove(x); A->inorder(); break;
            default : while (M--) {
                        scanf(" %d ", &x);
                        if (A->find(x)) B->insert(x);
                      }
                      A->clear();
                      swap(A, B);
                      A->inorder();
        }
        if (N) printf("\n");
    }
    return 0;
}
