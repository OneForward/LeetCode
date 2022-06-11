/*
leet497


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    VI S;
    VVI const *   prect;

    std::mt19937 gen{random_device{}()}; //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> rand_S;
    Solution(const VVI& rects) {
        S.reserve(rects.size());
        S.push_back(0);
        for (auto&& rect: rects) {
            auto a = rect[0], b = rect[1], x = rect[2], y = rect[3];
            S.push_back(S.back() + (x - a + 1) * (y - b + 1));
        }
        prect = &rects;

        gen = mt19937{random_device{}()};
        rand_S = uniform_int_distribution<>(0, S.back()-1);
    }
    
    VI pick() {
        auto k = rand_S(gen);
        auto pos = upper_bound(ALL(S), k) - S.begin() - 1;
        auto& rect = (*prect)[pos];
        auto a = rect[0], b = rect[1], x = rect[2];
        k -= S[pos];
        return {a + k % (x - a + 1), b + k / (x - a + 1)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

int main(int argc, char const *argv[])
{
    VVI rects = {{-2, -2, 1, 1}, {2, 2, 4, 6}};
    auto sol = Solution(rects);
    cout << sol.pick() << endl;
    cout << sol.pick() << endl;
    cout << sol.pick() << endl;
    cout << sol.pick() << endl;
    
    return 0;
}
