/*
    [模拟], [单链表]
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 1e5+11;

int N, M, x, ans = 0;

struct Node
{
    int val; 
    Node* next;
    Node(int v=0, Node* n=nullptr): val(v), next(n) {}
};

Node* rear = new Node(), *head = rear; // head不存储值
Node* p, *delNode;

bool isequal(Node* p, int val) { ans++; return p->val == val; }

int main(int argc, char const *argv[])
{
    #ifdef DEBUG
    freopen("sjtu1051/1.in", "r", stdin);
    #endif

    cin >> N;
    for (int i=0; i<N; ++i) scanf(" %d ", &x), rear->next = new Node(x), rear = rear->next;

    cin >> M;
    while (M--) {
        scanf(" %d ", &x);
        p = head;
        while (p->next) {
            if (isequal(p->next, x)) {
                head->next = new Node(x, head->next);
                delNode = p->next;
                p->next = delNode->next;
                delete delNode;
                break;
            }
            p = p->next;
        }
    }
    printf("%d", ans);
    return 0;
}
