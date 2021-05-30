/*
leet975


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int oddEvenJumps(const vector<int>& A) {
        bool f[100005][2]{};
        int ans = 0, N = A.size();
        map<int, int> M;
        M[-1] = M[100000] = N;

        f[N-1][0] = f[N-1][1] = true;

        auto g = [&](int i, int j, int z) {
            f[i][z] |= f[j][1-z];
        };

        for (int i = N - 1; i >= 0; i--)
        {
            auto x = A[i];
            auto p = M.lower_bound(x);

            g(i, p->second, 1);
            if (p->first == x) g(i, p->second, 0);
            else g(i, prev(p)->second, 0);

            M[x] = i; 
            if (f[i][1]) ans++; 
        }
        
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.oddEvenJumps({10,13,12,14,15}) << endl;
    cout << sol.oddEvenJumps({2,3,1,1,4}) << endl;
    cout << sol.oddEvenJumps({5,1,3,4,2}) << endl;
    cout << sol.oddEvenJumps({1,2,3,2,1,4,4,5}) << endl;
    return 0;
}
