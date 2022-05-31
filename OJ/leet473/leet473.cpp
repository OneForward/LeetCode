/*
leet473


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    VI vec;
    int sum;

    bool can_split(int x, const vector<int>& matchsticks) {
        vec.clear();
        int N = matchsticks.size();
        for (int i = 0; i < N; i++) {
            if ((1<<i) & x) vec.push_back(matchsticks[i]);
        }
        
        int M = vec.size();
        for (int x = 1; x < 1<<M; ++x) {
            long long sub = 0;
            for (int i = 0; i < M; i++) {
                if ((1<<i) & x) sub += vec[i];
            }
            if (sub == sum / 4) return true;
        }
        return false;
    };

    bool makesquare(const vector<int>& matchsticks) {
        sum = reduce(ALL(matchsticks), 0LL);
        if (sum % 4 != 0) return false;

        int N = matchsticks.size();
        for (int x = 1; x < 1<<N; ++x) {
            long long sub = 0;
            for (int i = 0; i < N; i++) {
                if ((1<<i) & x) sub += matchsticks[i];
            }
            if (sub == sum / 2 
                and can_split( x, matchsticks)
                and can_split(~x, matchsticks)
            ) return true;
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   cout << boolalpha;
    cout << sol.makesquare({1,1,2,2,2}) << endl;
    cout << sol.makesquare({3,3,3,3,4}) << endl;
    cout << sol.makesquare({}) << endl;
    return 0;
}
