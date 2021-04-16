/*
leet202


*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        // 模拟法
        // 其他方法包括，快慢指针法、硬编码法（把非1loop找到即可，其数字必定为 4->16->..->4）
        int ans = n; unordered_set<int> S;
        do {
            n = ans; ans = 0;
            while (n) {
                ans += (n % 10) * (n % 10);
                n /= 10;
            }
            // cout << ans << ", ";
            if (S.find(ans) == S.end()) S.insert(ans);
            else return false;
        } while (ans != 1);
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha << sol.isHappy(19) << endl;
    return 0;
}
