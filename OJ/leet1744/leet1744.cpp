/*
leet1744


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    vector<bool> canEat( vector<int> C, const vector<vector<int>>& queries) {
        long long f[100005]{}, N = C.size();
        for (int i = 0; i < N; i++)
            f[i + 1] = f[i] + C[i];
        
        vector<bool> ans; ans.reserve(queries.size());
        for (auto&& q: queries) {
            auto i = q[0], day = q[1], M = q[2];
            ans.push_back( f[i] / M <= day and day < f[i+1] );
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.canEat({7,4,5,3,8},  {{0,2,2},{4,2,4},{2,13,1000000000}}) << endl;
    cout << sol.canEat({5,2,6,4,1},  {{3,1,2},{4,10,3},{3,10,100},{4,100,30},{1,3,1}}) << endl;
    return 0;
}
