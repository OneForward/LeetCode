/*
leet678


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    bool checkValidString(string s) {
        int N = s.size();
        bool f[101][101]{};
        for (int i = 0; i < N; i++) f[i][i] = s[i] == '*';
        for (int i = 0; i < N-1; i++) f[i][i+1] = s[i] != ')' and s[i+1] != '(';
        
        auto check = [&](int i, int j) {
            if (s[i] == ')' or s[j] == '(') return false;
            if (f[i+1][j-1]) return true;
            for (int k = i; k < j; k++)
                if (f[i][k] and f[k+1][j])  return true;
            return false;
        };

        for (int len = 3; len <= N; len++)
        {
            for (int i = 0; i <= N-len; i++)
            {
                int j = i + len - 1;
                f[i][j] = check(i, j);
            }

        }
        return f[0][N-1];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.checkValidString("((") << endl;
    cout << sol.checkValidString("((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()") << endl;
    cout << sol.checkValidString("()") << endl;
    cout << sol.checkValidString("(*)") << endl;
    cout << sol.checkValidString("(*))") << endl;
    return 0;
}
