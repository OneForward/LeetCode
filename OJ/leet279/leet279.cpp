#include <stdio.h>
#include <cmath>

/*
Solution1:

C++ 递归 + 剪枝，36ms, 战胜90%

剪枝的要点有两个，一个是对深度超过目前最深的分解次数的结点不递归，一个是只对平方根中一半的数递归即可

Solution2:

[四平方数定理](https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem)
任何正整数均能分解为四个整数的平方和
[三平方数定理](https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem)
当且仅当 n ！= 4^a (8 b + 7) 时， n 可以分解为三个整数的平方和
[推论] 当 n = 4^a (8 b + 7) 时， n 只能分解为四个整数的平方和
[两平方数定理](https://en.wikipedia.org/wiki/Sum_of_two_squares_theorem)
对于任何大于1的整数，当且仅当其素因数分解中每一个模4余3的素因子的指数为偶数时其能分解为两个平方数之和
*/

class Solution1 {
public:

    #define INF 0x1fffffff

    const int M[8] = {0, 1, 2, 3, 1, 2, 3, 4};

    int numSquares(int n, int depth, int& minDepth) {
        if (depth >= minDepth) return INF;
        if (n <= 7) return M[n];
        int x = (int)(sqrt(n)); 
        int minSub = INF, subDepth;
        for (int t = x; t >= x/2 and t >= 2; --t) {
            subDepth =  numSquares(n - t * t, depth+1, minDepth);
            if (subDepth < minSub) minSub = subDepth;
        }
        return minSub + 1;
    }

    int numSquares(int n) {
        if (n <= 7) return M[n];
        int x = (int)(sqrt(n)); 
        int minDepth = INF, subDepth;
        for (int t = x; t >= x/2 and t >= 2; --t) {
            subDepth =  numSquares(n - t * t, 0, minDepth);
            if (subDepth < minDepth) minDepth = subDepth;
        }
        return minDepth + 1;
    }    

};



class Solution {
public:

    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        int b = (int)sqrt(n);
        if (n == b*b) return 1;
        int a;
        while (b) {
            a = (int)sqrt(n - b*b);
            if (a*a + b*b == n) return 2;
            --b;
        }
        return 3;
    }    

};

int main(int argc, char **argv)
{
    Solution1 sol;
	for (int i=1; i<=100; ++i)
        printf("numSquares(%d) = %d\n", i, sol.numSquares(i));
	return 0;
}
