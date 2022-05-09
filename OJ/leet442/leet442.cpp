/*
leet442


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& A) {
        vector<int> ans;
        for (auto x: A) {
            x = abs(x);
            if ( A[x - 1] < 0) ans.push_back( x );
            else A[x - 1] *= -1;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    {
        VI A {4,3,2,7,8,2,3,1}; 
        cout << sol.findDuplicates(A) << endl;
    }
    {
        VI A {1,1,2}; 
        cout << sol.findDuplicates(A) << endl;
    }
    {
        VI A {1}; 
        cout << sol.findDuplicates(A) << endl;
    }
    return 0;
}
