/*
leet047


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    VVI permuteUnique( VI A) {
        sort(ALL(A));
        
        VVI vs{{}};

        for (auto&& x: A) {
            VVI newvs;
            for (auto&& v: vs)
            {
                int len = v.size(), i = 0;
                for (i = 0; i < len; i++)
                {
                    auto newv = v;
                    newv.insert(newv.begin()+i, x);
                    newvs.push_back(newv);
                    if (v[i] == x) break;
                }
                if (i == len) v.push_back(x), newvs.push_back(v);
            }
            vs = newvs;
        }
        return vs;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.permuteUnique({1,1,2}) << endl;
    cout << sol.permuteUnique({1,2,2}) << endl;
    cout << sol.permuteUnique({1,1,1,2}) << endl;
    cout << sol.permuteUnique({1,1,2,2}) << endl;
    return 0;
}
