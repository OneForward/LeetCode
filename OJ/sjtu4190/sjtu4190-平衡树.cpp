/*
   问询区间[1..2k+1]的第k大值(即中位数)
*/

#include <iostream>
#include <set>
using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, x, y;
    multiset<int> S; 
    cin >> N >> x;
    cout << x << "\n";

    S.insert(x);
    auto mid = S.begin();
    for (int i = 1; i < N-1; i+=2) {
        cin >> x >> y;
        S.insert(x); S.insert(y);
        if (x < *mid and y < *mid) mid--;
        else if (x >= *mid and y >= *mid) mid++;
        cout << *mid << "\n";
    }

    return 0;
}
