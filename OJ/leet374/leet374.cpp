/*
leet374


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lft = 1, rht = n;
        while (lft < rht) {
            auto mid = lft + (rht - lft) / 2;
            if (guess(mid) <= 0) rht = mid;
            else lft = mid + 1;
        }
        return lft ;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
