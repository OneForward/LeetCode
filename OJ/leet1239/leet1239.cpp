/*
leet1239


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int maxLength(const vector<string>& A) {
        int ans = 0, N = A.size();
        for (int x = 0; x < 1<<N; x++)
        {
            int y = 0, len = 0;
            for (int i = 0; i < N; i++)
            {
                if ((1 << i) & x) {
                    for (auto&& ch: A[i]) {
                        if (y & (1 << (ch - 'a')))  goto bad;
                        y |= (1 << (ch - 'a')); len++;
                    }
                }
            }
            
            ans = max(ans, len);

            bad:;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxLength({"un","iq","ue"}) << endl;
    cout << sol.maxLength({"cha","r","act","ers"}) << endl;
    cout << sol.maxLength({"abcdefghijklmnopqrstuvwxyz"}) << endl;
    return 0;
}
