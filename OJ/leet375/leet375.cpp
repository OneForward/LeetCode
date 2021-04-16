#include <cstdio>

#define INF 0x7FFFFFFF 
#define max(x, y) (((x)>(y))?(x):(y))
class Solution {
public:
    int getMoneyAmount(int n) {
        int** A;
        A = new int*[n+2];
        for (int i=0; i<=n; ++i) A[i] = new int[n+2]();
        
        int ans, val;
        for (int i=1; i<=n; ++i) A[i][i+1] = i;
        int t = 1;
        while (t++ < n) {
            for (int i=1; i+t<=n; ++i) {
                int j = i+t;
                ans = INF;
                for (int k=i+1; k<j; ++k) {
                    val =  max(A[i][k-1], A[k+1][j]) + k;
                    if (ans > val) ans = val;
                }
                A[i][j] = ans;
            }
        }

        return A[1][n];
    }
};

int main(int argc, char **argv)
{

    int n = 10;
    Solution sol;
    for (int i=1; i<=n; ++i)
    printf("%d %d\n", i, sol.getMoneyAmount(i));

	return 0;
}
