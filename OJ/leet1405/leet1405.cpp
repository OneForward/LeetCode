/*
leet1405


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // 贪心, 0ms
        pair<int, char> f[] = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        sort(f, f+3);
        auto n1 = f[0].first, n2 = f[1].first;

        string s; 
        s.reserve(min(a+b+c, 3*n1+3*n2+2));

        while (true) {
            sort(f, f+3);

            auto& [p1, p2, p3] = f;
            auto& [n1, ch1] = p1;
            auto& [n2, ch2] = p2;
            auto& [n3, ch3] = p3;

            if (n3 - n2 >= 2) {
                if (s.empty() or s.back() != ch3) s.push_back(ch3), s.push_back(ch3), n3 -= 2;
                else s.push_back(ch2), n2--;
            }
            else {
                if (s.empty() or s.back() != ch3) s.push_back(ch3), n3--;
                else s.push_back(ch2), n2--;
            }
            if (n1 == 0 and n2 == 0 and s.back() == ch3) break;
        }
        return s;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestDiverseString(1,1,7) << endl;
    cout << sol.longestDiverseString(2,2,1) << endl;
    return 0;
}
