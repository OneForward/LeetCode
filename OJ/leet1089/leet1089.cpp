/*
leet1089


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    void duplicateZeros(vector<int>& A) {
        int N = A.size();
        int rht = 0, lft = 0;
        for ( ; ; lft++, rht++)
        {
            if (A[lft] == 0) rht++;
            if (rht >= N - 1) break;
        }


        if (rht == N) A.back() = 0, rht = N - 2, lft--;
        for (; lft >= 0; rht--, lft--)
        {
            A[rht] = A[lft];
            if (A[lft] == 0) A[--rht] = 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    
    {
        VI v {1,0,0,1,0};
        sol.duplicateZeros(v);
        cout << v << endl;
    }
    
    {
        VI v {1,0,2,3,0,4,5,0};
        sol.duplicateZeros(v);
        cout << v << endl;
    }

    {
        VI v {1,2,3};
        sol.duplicateZeros(v);
        cout << v << endl;
    }
    {
        VI v {0,0,0,0,0,0,0};
        sol.duplicateZeros(v);
        cout << v << endl;
    }
    return 0;
}
