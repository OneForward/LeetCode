/*
树状数组


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

struct BIT // 树状数组
{
    vector<int> L;
    int n;

    inline int lowbit(int x) {  return x & -x; }
    
    BIT(int _n): n{_n}, L(_n) {}

    int query(int i) { // 返回 [1, i] 的区间和
        int ans = 0;
        while (i) ans += L[i], i -= lowbit(i);
        return ans;
    }

    void update(int i, int x) { // A[i] += x
        while (i < n) L[i] += x, i += lowbit(i);
    }


    // 建树 O(N), 注意 A 和 L 的索引 是从 1 开始的
    BIT(const vector<int>& A): n{A.size()}, L{A} {
        for (int i = 0; i < n; ++i) { 
            int j = i + lowbit(i);
            if (j < n) L[j] += L[i];
        }
    }

};


int main(int argc, char const *argv[])
{
    
    return 0;
}
