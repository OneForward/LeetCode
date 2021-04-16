/*
   问询区间[1..2k+1]的第k大值(即中位数)
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, x;
    priority_queue<int> maxQ;
    // priority_queue minQ(greater<int>{}, vector<int>{});
    priority_queue<int, vector<int>, greater<int>> minQ;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> x;
        int n = maxQ.size(), m = minQ.size();
        if (n == m) {
            if (m and x >= minQ.top()) minQ.push(x);
            else maxQ.push(x);
        }
        else if (n > m) {   
            if (x >= maxQ.top()) minQ.push(x);
            else maxQ.push(x), minQ.push(maxQ.top()), maxQ.pop();
        }
        else {
            if (x <= minQ.top()) maxQ.push(x);
            else minQ.push(x), maxQ.push(minQ.top()), minQ.pop();
        }
        if (i & 1) cout << ( maxQ.size() > minQ.size() ? maxQ.top() : minQ.top() ) << "\n";
    }

    return 0;
}
