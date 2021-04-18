#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;



int N, M, w;
int A[3005];

int main()
{
    freopen("in.txt", "r", stdin);

    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> A[i];
    // sort(A, A+N);

    unordered_map<int, pair<int, int>> S;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            S[abs(A[j]-A[i])] = {A[i], A[j]};
        }
    }
    

    while (M--) {
        cin >> w;
        if (S.find(w) == S.end())  printf("-1 -1\n");
        else {
            auto [i, j] = S[w];
            printf("%d %d\n", i, j);
        }
    }
    
    
    return 0;
}
