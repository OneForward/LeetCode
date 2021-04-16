/*
leet028

KMP 字符串匹配算法

*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <utility>
using namespace std;

class Solution {
public:
    int strStr(string& S, string& T) {
        if (T.size() == 0) return 0;
        int* next = new int[T.size()];
        next[0] = -1; int pi, j;
        for (int i=1; i<T.size(); ++i) {
            pi = i-1;
            while (pi >= 0 && T[next[pi]+1] != T[i]) pi = next[pi];
            if (pi >= 0) next[i] = next[pi] +1;
            else next[i] = -1;
        }

        // for (int i=0; i<T.size(); ++i) printf("%d, ", next[i]); printf("\n");

        j = 0, pi = 0;
        while (pi < T.size() && j < S.size() ) {
            if (S[j] == T[pi]) j++, pi++;
            else if (pi == 0) ++j;
            else pi = next[pi-1]+1;
        }
        return  pi == T.size() ? j-pi : -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string S = "", T = "";
    printf("ans = %d\n", sol.strStr(S, T) );
    return 0;
}
