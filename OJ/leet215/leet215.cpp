/*
leet215


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


int partition(vector<int>& A, int lft, int rht) {
    swap(A[rht-1], A[rand()%(rht - lft) + lft]);
    
    rht--;
    auto x = A[rht];
    int j = lft;
    for (int i = lft; i < rht; i++)
    {
        if (A[i] > x) swap(A[i], A[j++]);
    }
    swap(A[rht], A[j]);
    return j;
}

class Solution {
public:
    int findKthLargest(vector<int> A, int k) {
        k--;
        int lft = 0, rht = A.size();
        while (lft < rht) {
            int p = partition(A, lft, rht);
            if (p >= k) rht = p;
            else lft = p + 1;
        }
        return A[lft];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findKthLargest( {3,2,1,5,6,4}, 2) << endl;
    cout << sol.findKthLargest( {3,2,3,1,2,4,5,5,6}, 4) << endl;
    return 0;
}
