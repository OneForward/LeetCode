/*
leet179


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
    string largestNumber(const vector<int>& nums) {
        // 24ms
        vector<vector<char>> v;
        for (auto x: nums) { 
            vector<char> vi;
            do {vi.push_back(x % 10 + '0'), x /= 10;} while (x);
            v.push_back(vi);
        }

        auto cmp = [] (const vector<char>& v1, const vector<char>& v2) {
            auto p1 = v1.rbegin(), p2 = v2.rbegin();
            
            while (true)  {
                while (p1 != v1.rend() && p2 != v2.rend()) {
                    if (*p1 > *p2) return true;
                    else if  (*p1 < *p2) return false;
                    else  p1++, p2++;
                }
                if (p1 != v1.rend()) p2 = v2.rbegin();
                else if (p2 != v2.rend()) p1 = v1.rbegin();
                else break;
            }
            return false;
        };

        sort(v.begin(), v.end(), cmp);

        vector<char> flat;
        for (const auto& vi: v) {
            for (auto pi = vi.rbegin(); pi != vi.rend(); ++pi) flat.push_back(*pi);
        }
        if (flat.empty() || flat[0] == '0') return "0";
        return string(flat.begin(), flat.end());
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   

    // vector v = { 3, 30, 34, 5, 9, 0 , 0, 3};
    // cout << sol.largestNumber({ 3, 30, 34, 5, 9, 0 , 0, 3}) << endl;
    // cout << sol.largestNumber({ 3, 30, 34, 5, 9}) << endl;
    // cout << sol.largestNumber({ 856, 8567, 8566, 8568, 8569, }) << endl;
    // cout << sol.largestNumber({ 12, 121212121, }) << endl;
    // cout << sol.largestNumber({ 0, 0, 0, }) << endl;

    cout << sol.largestNumber({ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,
            }) << endl;
    return 0;
}
