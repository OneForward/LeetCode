/*

    队列, 队列的队列, 延迟哈希
*/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{
    // freopen("hw05_01_cases/case_01.in", "r", stdin);
    unordered_map<int, int> M;
    vector<queue<int>> Q;

    int N, query, event, G[200'0005], gid = 0, n = 1, start = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {  
        scanf("%d", &G[i]); // 第i个人归属的团体编号
    }

    scanf("%d", &query);
    while (query--) {
        scanf("%d", &event); // 事件
        
        if (event == 0) { // 插入新人到所在的小团体后
            if (n > N) continue;
            gid = G[n]; // 第 n 个人归属的团体编号
            // 如果队列中有自己的团体，插到小团体队伍
            if (M.find(gid) != M.end() and M[gid] >= start) {
                Q[M[gid]].push(n);
            }
            else { // 插到队尾
                M[gid] = Q.size();
                Q.emplace_back();
                Q.back().push(n);
            }
            n++;
        }
        else { // 队首离开
            if (start == (int)Q.size()) {
                printf("-1\n"); continue;
            }
            
            // 队首出队
            printf("%d\n", Q[start].front());
            Q[start].pop();
            
            // 如果队首的小团体没人了，移除该小团体编号
            if (Q[start].empty()) start++;
        }
    }
    return 0;
}
