/*
    (稀疏数组)
    动作: 交换行列
    问询: 值
    技巧: 保存行行、列列映射, O(N)空间
    链表+链表保存稀疏数据
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 1e5+5;

int N, M, x, y, z, op;
int rowMap[MAX_N];
int colMap[MAX_N];

struct Node
{
    int col;
    int val;
    Node* next;
    Node(int c=0, int v=0, Node* n=nullptr)
        :col(c), val(v), next(n) {}
    int find(int _col) {
        Node* p = this;
        while (p and p->col != _col) p = p->next;
        if (p) return p->val;
        else return 0;
    }
};

Node* A[MAX_N];

int main(int argc, char const *argv[])
{

    scanf("%d", &N);

    while (N--) {
        scanf("%d %d %d ", &x, &y, &z);
        A[x] = new Node(y, z, A[x]);
    }
    
    for (int i=0; i<MAX_N; ++i) rowMap[i] = i, colMap[i] = i;

    scanf("%d", &M);
    while(M--) {
        scanf("%d %d %d ", &op, &x, &y);
        switch (op) {
            case 0: swap(rowMap[x], rowMap[y]); break;
            case 1: swap(colMap[x], colMap[y]); break;
            default:
                printf("%d\n", A[rowMap[x]]->find(colMap[y]));
        }
    }
    return 0;
}
