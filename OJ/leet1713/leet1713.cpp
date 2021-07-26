/*
leet1713


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int minOperations(const vector<int>& target, const vector<int>& A) {
        unordered_map<int, int> M;
        for (auto&& x: target) M[x] = M.size();
        vector<int> I; I.reserve(A.size());
        for (auto&& x: A) {
            if (M.find(x) != M.end()) I.push_back( M[x]);
        }

        vector<int> v;
        for (auto&& i: I) {
            auto pos = lower_bound(ALL(v), i);
            if (pos == v.end()) v.push_back(i);
            else *pos = i;
        }
        return target.size() - v.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minOperations({5,1,3}, {9,4,2,3,4}) << endl;
    cout << sol.minOperations({6,4,8,1,3,2}, {4,7,6,2,3,8,6,1}) << endl;
    return 0;
}
