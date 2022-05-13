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
                for (int i = 0; i <= v.size(); i++)
                {
                    auto newv = v;
                    newv.insert(newv.begin()+i, x);
                    newvs.push_back(newv);
                    if (i < v.size() and v[i] == x) break;
                }
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
