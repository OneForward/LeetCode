/*
leet241


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    VI f(const string_view& e) {
        if (e.empty()) return {};

        VI ans;
        for (size_t i = 1; i < e.size(); i++)
        {
            if (isdigit(e[i])) continue;
            auto vlft = f(e.substr(0, i));
            auto vrht = f(e.substr(i + 1, e.npos));
            for (auto&& lft: vlft) {
                for (auto&& rht: vrht ) {
                    auto x = lft + rht;
                    if (e[i] == '-') x = lft - rht;
                    if (e[i] == '*') x = lft * rht;
                    ans.emplace_back(x);
                }
            }
        }
        if (ans.empty()) ans = { stoi(string{e}) };
        return ans;
    }

    vector<int> diffWaysToCompute(const string& expression) {
        return f(expression);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.diffWaysToCompute("2-1-1") << endl;
    cout << sol.diffWaysToCompute("2*3-4*5") << endl;
    return 0;
}
