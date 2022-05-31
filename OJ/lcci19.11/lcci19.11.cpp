/*
lcci19.11


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int findClosest(const vector<string>& words, const string& word1, const string& word2) {
        int lft = -1, rht = -1, N = words.size();
        int dist = INT_MAX;
        for (int i = 0; i < N and dist; i++)
        {
            if (words[i] == word1) lft = i;
            else if (words[i] == word2) rht = i;
            
            if (lft != -1 and rht != -1) {
                dist = min(dist, abs(lft - rht));
            }
        }
        
        return dist;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findClosest({ "I","am","a","student","from","a","university","in","a","city"}, "a", "student" ) << endl;
    return 0;
}
