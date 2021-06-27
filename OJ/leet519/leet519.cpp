/*
leet519


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;




using Pair = pair<int, int>;
template<> struct std::hash<Pair>
{
    size_t operator() (const Pair& pair ) const {
        return pair.first * 10000 + pair.second;
    }
};

class Solution {
public:
    unordered_set<Pair> used;
    int R, C;
    Solution(int r, int c): R{r}, C{c} { }
    
    vector<int> flip() {
        while (true) {
            auto r = rand() % R, c = rand() % C;
            if (used.find({r, c}) == used.end()) {
                used.insert({r, c});
                return {r, c};
            }
        }
    }
    
    void reset() {
        used.clear();
    }
};




int main(int argc, char const *argv[])
{
    // Solution sol;   
    
    return 0;
}
