/*
shopee0802


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;



class Solution {
public:


    int f(int N, int m, int K) {
        if (K == 1) return 1;

        int cnt = 0;
        for (int x = m; x <= N - m; x++)
        {
            auto y = N - x;
            if (y >= x) cnt += f(y, x, K - 1);
            else break;
        }
        return cnt;
    }

    int divide(int N, int k) {
        return f(N, 1, k);
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.divide(7, 2) << endl;
    for (int N = 3; N < 11; N++)
    {
    cout << N << ", " << sol.divide(N, 3) << endl;
    }
    
    return 0;
}
