/*
leet149


*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    
    int maxPoints(const vector<vector<int>>& points) {
        if (points.empty()) return 0;

        auto f = [] (const vector<int>& p1, const vector<int>& p2)  {
            int y = (p1[1] - p2[1]), x = (p1[0] - p2[0]);
            
            return (double)y / x;
        };
        
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            const auto& p1 = points[i];
            unordered_map<double, int> M; int Vertical = 0;
            for (int j = i+1; j < points.size(); ++j) {
                const auto& p2 = points[j];
                if (p1[0] == p2[0]) Vertical++;
                else  M[f(p2, p1)]++; 
            }
            ans = max(ans, Vertical);
            for (const auto& [k, v]: M)  ans = max(ans, v);
        }
        return ans + 1;
    }
};

int main(int argc, char const *argv[])
{
    // cout << gcd(1, 2) << endl;
    // cout << gcd(-1,-2) << endl;
    // cout << gcd(-1,-1) << endl;
    // cout << gcd(1,-1) << endl;
    // cout << gcd(-1,1) << endl;
    // cout << gcd(0, 1) << endl;
    // cout << gcd(1, 0) << endl;
    // cout << gcd(96, 120) << endl;
    // cout << gcd(96, -120) << endl;
    // cout << gcd(-96, 120) << endl;
    // cout << gcd(-96, -120) << endl;
    Solution sol;   
    // cout << sol.maxPoints( { {1,1},{3,2},{5,3},{4,1},{2,3},{1,4} } ) << endl;
    // cout << sol.maxPoints( { {1,1},{2,2},{3,3} } ) << endl;
    // cout << sol.maxPoints( { {1,1},{2,2},{1,1} } ) << endl;
    // cout << sol.maxPoints( { {1,1},{2,2}, } ) << endl;
    // cout << sol.maxPoints( { {1,1}, } ) << endl;
    // cout << sol.maxPoints( {  } ) << endl;
    // cout << sol.maxPoints( { {0,0},{94911151,94911150},{94911152,94911151} } ) << endl;
    // cout << sol.maxPoints( { {-4,1},{-7,7},{-1,5},{9,-25} } ) << endl;
    // cout << sol.maxPoints( { {2,3},{3,3},{-5,3} } ) << endl;
    cout << sol.maxPoints( { {0,0},{65536,65536},{65536,131072} } ) << endl;
    return 0;
}
