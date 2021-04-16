
#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>
#include <utility>

using namespace std;

int lower_bound(int A[], int lft, int rht, int x) {
    // 在 A[lft, rht) 中二分搜索，保证了 A 递增
    // lower_bound: 返回第一个 >= x 的位置
    while (lft < rht) {
        auto mid = lft + (rht - lft) / 2;
        if (A[mid] >= x) rht = mid;
        else lft = mid + 1;
    }
    return rht;
}

int upper_bound(int A[], int lft, int rht, int x) {
    // 在 A[lft, rht) 中二分搜索，保证了 A 递增
    // upper_bound: 返回第一个 > x 的位置
    while (lft < rht) {
        auto mid = lft + (rht - lft) / 2;
        if (A[mid] > x) rht = mid;
        else lft = mid + 1;
    }
    return rht;
}


int main(int argc, char const *argv[])
{
    int A[] = {1, 2, 2, 2, 3, 3, 4, 5};
    cout << lower_bound(A, 0, 8, 0) << endl;
    cout << lower_bound(A, 0, 8, 1) << endl;
    cout << lower_bound(A, 0, 8, 2) << endl;
    cout << lower_bound(A, 0, 8, 5) << endl;
    cout << lower_bound(A, 0, 8, 6) << endl; cout << endl;

    cout << upper_bound(A, 0, 8, 0) << endl;
    cout << upper_bound(A, 0, 8, 1) << endl;
    cout << upper_bound(A, 0, 8, 2) << endl;
    cout << upper_bound(A, 0, 8, 5) << endl;
    cout << upper_bound(A, 0, 8, 6) << endl;
    return 0;
}
