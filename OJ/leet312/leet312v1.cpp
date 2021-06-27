/*
leet312


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> f;
    vector<int> A;
    int solve(int i, int j) {
        if (i >= j-1) return 0;
        if (f[i][j] != -1) return f[i][j];
        for (int k = i + 1; k < j; ++k) {
            f[i][j] = max(f[i][j], solve(i, k) + A[i] * A[k] * A[j] + solve(k, j) );
        }
        return f[i][j];
    }
    int maxCoins(const vector<int>& nums) {
        A = {1};
        A.insert(A.end(), nums.begin(), nums.end());
        A.push_back(1);

        int n = A.size();
        f.resize(n, vector<int>(n, -1));
        return solve(0, n-1);

    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
