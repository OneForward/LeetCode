/*
旅行商问题-TSP
城市数目C<=5，暴力穷举，至多120种情况
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

struct Pos
{
   int row, col, color;
   Pos* prev;
   Pos(int r, int c): row(r), col(c), color(0), prev(nullptr) {}
};

struct Queue
{ // 使用循环数组实现，head做队伍头标志，不存储信息
    Pos** buffer;
    int size, head, tail;
    Queue(int N):size(N), head(0), tail(0) { buffer = new Pos*[N]; }
    ~Queue() { delete [] buffer; }

    void push(Pos* x) {
        tail = (tail + 1) % size;
        buffer[tail] = x;
    }

    Pos* pop() {
        head = (head + 1) % size;
        return buffer[head];
    }

    bool isempty() { return head == tail; }
};

enum COLOR{ WHITE, GRAY, BLACK };
int N, M, gold_cnt = 1;
int** maze;
Pos*** P;
Pos* pos, *start;
Pos* Gold[10];
Pos* neighbors[4];
int Dist[10][10] = {0};
int arr[10] = {};

void init() {
    maze = new int*[N+1];
    for (int i=0; i<N+1; ++i) maze[i] = new int[M+1];

    P = new Pos**[N+2];
    for (int i=0; i<N+2; ++i) P[i] = new Pos*[M+2];
    for (int i=0; i<N+2; ++i)
        for (int j=0; j<M+2; ++j)
            P[i][j] = new Pos(i, j);

    for (int i = 0; i < 10; ++i) arr[i] = i;
}

bool isvalid(int row, int col) {
    return 1 <= row and row <= N and 1 <= col and col <= M and
            maze[row][col] != -1 and
            P[row][col]->color == WHITE;
}

bool isvalid(Pos* u) { return isvalid(u->row, u->col); }

Pos* left(Pos* u) { return P[u->row-1][u->col]; }
Pos* right(Pos* u) { return P[u->row+1][u->col]; }
Pos* up(Pos* u) { return P[u->row][u->col-1]; }
Pos* down(Pos* u) { return P[u->row][u->col+1]; }

void set_neighbors(Pos* u) {
    neighbors[0] = left(u);
    neighbors[1] = right(u);
    neighbors[2] = up(u);
    neighbors[3] = down(u);
}

bool bfs(int root) {
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=M; ++j)
            P[i][j]->color = WHITE, P[i][j]->prev = nullptr;
    
    Pos* u = Gold[root];
    Queue Q(N*M);
    Q.push(u); u->color = GRAY;
    while (not Q.isempty()) {
        pos = Q.pop();
        set_neighbors(pos);
        for (Pos* p: neighbors)
            if (isvalid(p)) Q.push(p), p->color = GRAY, p->prev = pos;
    }

    for (int i=0; i<gold_cnt and i!=root; ++i) {
        pos = Gold[i];
        if (pos->color == GRAY) {pos = pos->prev; while (pos) Dist[root][i]++, Dist[i][root]++, pos = pos->prev;}
        else return false;
    }
    return true;
}

int next_permutate() {
    int MAX_N = gold_cnt-1, pNum = MAX_N-1, cNum = MAX_N;
    while (pNum >= 1 and arr[pNum] > arr[pNum+1]) pNum--;
    while (cNum > pNum and arr[cNum] < arr[pNum]) cNum--;
    swap(arr[cNum], arr[pNum]); 
    for (int i = 1; i <= (MAX_N-pNum)/2; ++i)
        swap(arr[pNum+i], arr[MAX_N+1-i]);

    return pNum;
}

int get_distance() {
    int d = 0;
    for (int i = 0; i < gold_cnt-1; ++i) d += Dist[arr[i]][arr[i+1]];
    return d;
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;
    init();
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            scanf("%d", &(maze[i][j]));
            if (maze[i][j] == 2) start = P[i][j];
            else if (maze[i][j] == 1) Gold[gold_cnt++] = P[i][j];
        }
    }
    Gold[0] = start;

    bool found = false;
    for (int i=0; i<gold_cnt; ++i) {
        found = bfs(i);
        if (not found) break;
    }

    
    if (not found) cout << -1;
    else {
        int min_dist = 1e8, d;
        do {
            d = get_distance();
            if (d < min_dist) min_dist = d;
        } while (next_permutate() != 0);
        cout << min_dist;
    }

    return 0;
}
