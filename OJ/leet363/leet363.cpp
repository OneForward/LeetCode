#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if ( k < 0) return k;

        int length = matrix.size() + 1, width = matrix[0].size() + 1;
        vector<int> A(length*width, 0);
        
        for (int i=1; i<length; ++i) {
            for (int j=1; j<width; ++j) {
                A[i*width+j] = A[(i-1)*width+j] + A[i*width+j-1] - A[(i-1)*width+j-1] + matrix[i-1][j-1];
            }
        }
        sort(A.begin(), A.end());
        int ans = 0; vector<int>::iterator it = A.end();
        for (int i=length*width-1; i>=0; --i) {
            it = lower_bound(A.begin(), it, A[i]-k);
            if (*it == A[i]-k) return k;
            else if (ans < A[i] - *it) ans = A[i] - *it;
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    // freopen("leet363/1.in", "r", stdin);

    int length, width;
    cin >> length >> width;
    
    vector<vector<int>> M{{2,2,-1}};
    int k = 2;
    
    Solution solution;
    int ans = solution.maxSumSubmatrix(M, k);

    printf("ans = %d\n", ans);

    return 0;
        
}
