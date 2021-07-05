/*
leet726


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    string countOfAtoms(string s) {
        
        vector<pair<string, int>> v;
        auto fetch_digit = [&](size_t& i) {
            if (not isdigit(s[i])) return 1;
            int x = 0;
            while (isdigit(s[i])) x = x * 10 + (s[i] - '0'), ++i;
            return x;
        };

        auto fetch_string = [&](size_t& i) {
            string name {s[i++]};
            while (islower(s[i])) name.push_back(s[i++]);
            return name;
        };



        for (size_t i = 0; i < s.size(); )
        {

            if (s[i] == '(') {
                v.push_back({"(", 0}); ++i; continue;
            }
            if (s[i] == ')') {
                auto x = fetch_digit(++i);
                for (auto p = v.rbegin(); ; ++p) {
                    if (p->first == "(") {
                        v.erase((p+1).base()); break;
                    }
                    p->second *= x;
                } 
                continue;
            }
            auto name = fetch_string(i); 
            auto cnt = fetch_digit(i); 
            v.push_back({name, cnt});
        }

        map<string, int> M; 
        string ans;
        for (auto&& [name, cnt]: v) {
            M[name] += cnt;
        }
        for (auto&& [name, cnt]: M) {
            ans += name + (cnt > 1 ? to_string(cnt) : "");
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.countOfAtoms("H2O") << endl;
    cout << sol.countOfAtoms("Mg(OH)2") << endl;
    cout << sol.countOfAtoms("K4(ON(SO3)2)2") << endl;
    cout << sol.countOfAtoms("Be32") << endl;
    return 0;
}
