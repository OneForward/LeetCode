/*
leet992


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(const vector<int>& A, int K) {
        int M1[20005]{}, M2[20005]{};
        int r1{}, r2{}, c1{}, c2{}, n(A.size()), ans{};
        for (const auto& x: A) {
            // A[lft] = x; 我们希望 #[lft, r1) = K 以及 #[lft, r2) = K+1
            // 注意 r1, r2 会比实际大1
            while (c1 < K and r1 < n) {
                if (M1[A[r1]] == 0) c1++;
                M1[A[r1]]++; r1++;
            }
            while (c2 <= K and r2 < n) {
                if (M2[A[r2]] == 0) c2++;
                M2[A[r2]]++; r2++;
            }
            if (c1 < K) break; // r1 已经出界，仍未找到

            ans += r2 - r1; // [r1-1, r2-2]
            if (c2 == K) ans++; // r2 == n, 无法延长了，此时实际合法区间为 [r1-1, r2-1]
            M1[x]--; if (M1[x] == 0) c1--;
            M2[x]--; if (M2[x] == 0) c2--;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.subarraysWithKDistinct({1,2,1,2,3}, 2) << endl;
    cout << sol.subarraysWithKDistinct({1,2,1,3,4}, 3) << endl;
    return 0;
}
