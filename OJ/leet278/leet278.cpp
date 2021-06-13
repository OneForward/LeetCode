/*
leet278


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int v) {}

class Solution {
public:
    int firstBadVersion(long long n) {
        long long lft = 1, rht = n + 1;
        while (lft < rht) {
            auto mid = lft + (rht - lft) / 2;
            if (isBadVersion(mid)) rht = mid;
            else lft = mid + 1;
        }
        return lft;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
