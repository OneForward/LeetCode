/*
leet1340


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int maxJumps(const vector<int>& A, int d) {
        int N = A.size();
        VI M(N);
        function<int(int)> f = [&](int i) {
            if (M[i]) return M[i];
            int fi = 1;
            for (int j = i - 1; j >= max(0, i - d) and A[i] > A[j]; --j) {
                fi = max(fi, f(j) + 1);
            }
            for (int j = i + 1; j <= min(N - 1, i + d) and A[i] > A[j]; ++j) {
                fi = max(fi, f(j) + 1);
            }
            return M[i] = fi;
        };

        for (int i = 0; i < N; i++) {
            f(i);
        }
        return *max_element(ALL(M));
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxJumps({22,29,52,97,29,75,78,2,92,70,90,12,43,17,97,18,58,100,41,32}, 17) << endl;
    cout << sol.maxJumps({6,4,14,6,8,13,9,7,10,6,12}, 2) << endl;
    cout << sol.maxJumps({3,3,3,3,3}, 3) << endl;
    cout << sol.maxJumps({7,6,5,4,3,2,1}, 1) << endl;
    cout << sol.maxJumps({7,1,7,1,7,1}, 2) << endl;
    cout << sol.maxJumps({1}, 1) << endl;
    return 0;
}
