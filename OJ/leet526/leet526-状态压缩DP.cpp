/*
leet526


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:

    int countArrangement(int n) {
        // 状态压缩 DP
        // f[010101] 代表数字 1 3 5 放在前三位且合法的排列的数目
        // 转移: f[010111] += f[010101] 指的是 2 放入第 4 位（合法）
        vector<int> f(1 << n);
        for (size_t i = 0; i < n; i++)
        {
            f[1 << i] = 1;
        }

        for (size_t i = 0; i < (1 << n); i++)
        {
            // 计算 i 中 1 的数目
            int cnt = 1, x = i;
            while (x) {
                x &= x-1; ++cnt;
            }

            for (size_t j = 0; j < n; j++)
            {
                if (not(i & (1<<j)) and (
                    (j + 1) % cnt == 0 || cnt % (j + 1) == 0
                ) ) {
                    f[i | (1 << j)] += f[i];
                }
            }
            
        }
        
        
        return f.back(); // f[1....1]
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.countArrangement(2) << endl;
    cout << sol.countArrangement(3) << endl;
    return 0;
}
