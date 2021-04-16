/*
    迷宫
    bfs, 注意细节
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 111;

struct Pos
{
    int x, y, dist;
    Pos(int _x=0, int _y=0, int d=0): x(_x), y(_y), dist(d) {}

    Pos up() { return Pos(x-1, y, dist+1); }
    Pos dn() { return Pos(x+1, y, dist+1); }
    Pos lf() { return Pos(x, y-1, dist+1); }
    Pos rt() { return Pos(x, y+1, dist+1); }
};
 struct Node
{
    Pos pos;
    Node* next;
    Node(const Pos& p=Pos(), Node* n=nullptr):pos(p), next(n) {}
};

struct Queue
{
    Node* head, *tail;
    Queue() { head = tail = new Node();}
    void push(const Pos& pos) {
        tail->next = new Node(pos); tail = tail->next;
    }
    Pos pop() {
        Node* tmp = head; head = head->next;
        delete tmp;
        return head->pos;
    }
    bool isempty() { return head == tail; }
};

int N, M, x1, y1, x2, y2;
char Maze[MAX_N][MAX_N];
Queue Q;
bool visited[MAX_N][MAX_N] = {false};

bool isvalid(const Pos& pos) {
    return not visited[pos.x][pos.y];
}

int main(int argc, char const *argv[])
{

    cin >> N >> M >> x1 >> y1 >> x2 >> y2;
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=M; ++j)
            scanf(" %c ", &Maze[i][j]);
    for (int i=0; i<=N+1; ++i)
        for (int j=0; j<=M+1; ++j)
            if (Maze[i][j] == 0 or Maze[i][j] == '*') visited[i][j] = true;
    
    Pos pos, p, src(x1, y1); bool found = false;
    Q.push(src); visited[src.x][src.y] = true;

    while (not Q.isempty()) {
        pos = Q.pop();
        if (pos.x == x2 and pos.y == y2) { found = true; break; }
        switch(Maze[pos.x][pos.y]) {
            case '|': if ( isvalid(p = pos.up()) and Maze[p.x][p.y] != '-') { visited[p.x][p.y] = true; Q.push(p); }
                      if ( isvalid(p = pos.dn()) and Maze[p.x][p.y] != '-') { visited[p.x][p.y] = true; Q.push(p); } break;
            case '-': if ( isvalid(p = pos.lf()) and Maze[p.x][p.y] != '|') { visited[p.x][p.y] = true; Q.push(p); }
                      if ( isvalid(p = pos.rt()) and Maze[p.x][p.y] != '|') { visited[p.x][p.y] = true; Q.push(p); } break;
            default : if ( isvalid(p = pos.up()) and Maze[p.x][p.y] != '-') { visited[p.x][p.y] = true; Q.push(p); }
                      if ( isvalid(p = pos.dn()) and Maze[p.x][p.y] != '-') { visited[p.x][p.y] = true; Q.push(p); }
                      if ( isvalid(p = pos.lf()) and Maze[p.x][p.y] != '|') { visited[p.x][p.y] = true; Q.push(p); }
                      if ( isvalid(p = pos.rt()) and Maze[p.x][p.y] != '|') { visited[p.x][p.y] = true; Q.push(p); }
        }
    }
    if (found) cout << pos.dist;
    else cout << -1;
    return 0;
}
