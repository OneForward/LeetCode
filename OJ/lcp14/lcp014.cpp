/*
lcp014


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
// 太难
public:
    int splitArray(const vector<int>& A) {
        // 欧拉筛法
        // min_prime[x] 保存了 数字 x 的最小质因数
        int min_prime[1000010]{}, prime[100010]{};
        int cnt = 0, M = 0;
        for (const auto& x: A) M = max(M, x);

        for (size_t x = 2; x <= M; x++)
        {
            if (min_prime[x] == 0) {
                min_prime[x] = x; // x 是个质数
                prime[cnt++] = x;
            }
            for (size_t j = 0; j < cnt and x * prime[j] <= M; j++)
            {
                min_prime[x * prime[j]] = prime[j]; 
                if (x % prime[j] == 0) break; // pj 是第一个整除 x 的质数，之后的 x * pk 的最小质因数应当是 pj 了
            }
        }
        
        // 动态规划
        // f[px] = min(f[px], premin+1);
        // 对新增加的数 x, 考察其所有质因数 px
        // 假若新增的 px 是全新的质数，显然要单独一组
        // 
        int premin = 0;
        vector<int> f(1000010, INT_MAX);
        for (auto x: A) {
            int curmin = INT_MAX;
            while (x > 1) {
                int px = min_prime[x];
                f[px] = min(premin+1, f[px]);
                curmin = min(curmin, f[px]);
                x /= px;
            }
            premin = curmin;
        }
        return premin;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.splitArray({2,3,3,2,3,3}) << endl;
    cout << sol.splitArray({2,3,5,7}) << endl;
    return 0;
}
