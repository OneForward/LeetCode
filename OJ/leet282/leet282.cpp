/*
leet282


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    using Tuple = tuple<string, int>;
    using VT = vector<Tuple>;

    VT f(const string_view& e) {
        if (e.empty()) return {};

        VT ans = { Tuple{ e, stoi(string{e}) } };
        for (size_t i = 1; i < e.size(); i++)
        {
            auto vlft = f(e.substr(0, i));
            auto vrht = f(e.substr(i, e.npos));
            for (auto&& [elft, lft]: vlft) {
                for (auto&& [erht, rht]: vrht ) {
                    ans.emplace_back( Tuple{ elft + '+' + erht, lft + rht } );
                    ans.emplace_back( Tuple{ elft + '-' + erht, lft - rht } );
                    ans.emplace_back( Tuple{ elft + '*' + erht, lft * rht } );
                }
            }
        }
        return ans;
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        for (auto&& [e, x]: f(num)) {
            if (x == target) ans.emplace_back(e);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.addOperators("123", 6) << endl;
    cout << sol.addOperators("232", 8) << endl;
    cout << sol.addOperators("3456237490", 9191) << endl;
    return 0;
}
