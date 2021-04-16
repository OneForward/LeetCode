
/*
    搬箱子, 模拟, 数组实现双向链表, 计算双向链表的头尾
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 30;
int N, a, b;

char verb[10], prep[10];
int prevNode[MAX_N], nextNode[MAX_N];

void init() {
    for (int i = 0; i <= N; ++i) prevNode[i] = nextNode[i] = -1;
}

void reset_up(int x) {
    int p = nextNode[x], tmp;
    while (p >= 0) {
         tmp = p; p = nextNode[p];
         prevNode[tmp] = nextNode[tmp] = -1; 
    }
    nextNode[x] = -1;
}

int findNext(int x) {
    if (nextNode[x] < 0) return x;
    return findNext(nextNode[x]);
}

int findPrev(int x) {
    if (prevNode[x] < 0) return x;
    return findPrev(prevNode[x]);
}

void put_on(int a, int b) { // put a and a.up onto b.up
    int b_up = findNext(b);
    nextNode[prevNode[a]] = -1;
    nextNode[b_up] = a; prevNode[a] = b_up;
}

void output() {
    int p;
    for (int i=0; i<N; ++i) 
    {
        printf("%d:", i);
        if (prevNode[i] < 0) 
        {
            printf(" %d", i);
            if (nextNode[i] >= 0) 
            {
                p = nextNode[i];
                while (p >= 0) printf(" %d", p), p = nextNode[p];
            }
        }
        cout << endl;
    }
}


int main(int argc, char const *argv[])
{

    cin >> N;

    init();

    while (true) {

        scanf("%s", verb);
        if (verb[0] == 'q') break;

        scanf("%d %s %d", &a, prep, &b);

        if (findPrev(a) == findPrev(b))  continue;

        if (verb[0] == 'm')  // "move"
            reset_up(a);

        if (prep[2] == 't') // "onto", reset b.up
            reset_up(b);
        put_on(a, b);
    }

    output();

    return 0;
}
