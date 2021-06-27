/*
leet698


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    // 204ms
    bool canPartitionKSubsets(vector<int> A, int k) {
        auto sum = reduce(A.begin(), A.end(), 0);
        if (sum % k) return false;
        return f(A, sum / k, k);
    }

    bool f(vector<int> A, int target, int k) {
        if (k == 0) return true;
        if (k == 1) {
            auto sum = reduce(A.begin(), A.end(), 0);
            return sum == target;
        }
        int n = A.size();
        for (int i = 0; i < (1<<n); i++)
        {
            auto sum = 0;
            for (int x = 0; (1<<x) <= i; x++)
            {
                if ((1<<x) & i) sum += A[x];
            }
            if (sum == target) {
                vector<int> B;
                for (int x = 0; (1<<x) <= i; x++)
                {
                    if (((1<<x) & i) == 0) B.push_back(A[x]);
                }
                auto ok = f(B, target, k-1);
                if (ok) return true;
            }
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.canPartitionKSubsets({4, 3, 2, 3, 5, 2, 1}, 4) << endl;
    return 0;
}
