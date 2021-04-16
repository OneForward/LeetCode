#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>

using namespace std;

const char NORMAL = 0, REPEATE = 'R', Universal = 'U';
struct State {
    char state = 0;
    char data = 0;
    
    State(char s=0, char d=0):state(s), data(d) {}
    bool operator==(const State& o) const { return state == o.state && data == o.data; }
    bool operator!=(const State& o) const { return !(*this == o); }
};

// 对pattern 进行了预处理化简, 4ms, 96%
tuple<bool, vector<State>> prepocess(const string& p) {
    vector<State> v;
    if (p.length() && p[0] == '*') return {false, v};

    int i = 0;
    while (i < p.length()) {
        if (i < p.length()-1 && p[i] == '.' && p[i+1] == '*') {
            if (v.size() ==0 || (v.size() > 0 && v.back().state != Universal) ) {
                while (v.size() > 0 && v.back().state == REPEATE) v.pop_back();
                v.push_back({Universal});
            }
            i += 2; continue;
        }
        
        if (i < p.length()-1 && p[i] == '*' && p[i+1] == '*') return {false, v};
        if (i < p.length()-1 && p[i+1] == '*') { 
            if (v.size() == 0 ||( ( v.back() != State({REPEATE, p[i]}) ) && v.back().state != Universal) )
                v.push_back({REPEATE, p[i]}); 
            i += 2; continue; 
        }
        v.push_back({NORMAL, p[i]}); i += 1;
    }

    return {true, v};
}

// 递归方法
class Solution {

public:

    bool isMatch(const string& s, const vector<State>& p, int is, int ip) {

        while ( is < s.length() && ip < p.size() )
        {   

            if ( p[ip].state == REPEATE ) { 
                // [a-z]*

                for (int i=is; i<s.length(); ++i) {
                    if (s[i] == p[ip].data) {
                        if (isMatch(s, p, i+1, ip+1)) return true; // >=1 times
                    }
                    else break;
                }
                return isMatch(s, p, is, ip+1); // 0 times
            }

            if ( p[ip].state == Universal ) { 
                // .*[]
                for (int i=is; i<=s.length(); ++i) {
                    if (isMatch(s, p, i, ip+1)) return true; 
                }
                return false;
            }

            if (s[is] == p[ip].data || p[ip].data == '.') {
                is++, ip++; continue;
            }

            return false;
        }
        
        for (int i=ip; i < p.size(); ++i) {
            if (p[i].state != REPEATE && p[i].state != Universal) return false;
        }
        return is == s.length();
    }

    bool isMatch(string s, string p) {
        auto [ok, new_p] = prepocess(p);
        return ok && isMatch(s, new_p, 0, 0);
    }
};

int main(int argc, char const *argv[])
{
    string s = ""; string p = "a*c*a*b*.*aa*c*a*a*";

    Solution solution;
    auto [ok, new_p] = prepocess(p);
    for (auto& pi: new_p) {
        printf("(%c, %c)->\n", pi.state, pi.data);
    }
    // assert()
    cout << boolalpha << solution.isMatch("c", "c*a*") << endl;
    cout << boolalpha << solution.isMatch(
"ac",
"a*c*a*b*.*aa*c*a*a*"
    ) 
    << endl;
    cout << boolalpha << solution.isMatch(
"cbaacacaaccbaabcb",
"c*b*b*.*ac*.*bc*a*"
    ) 
    << endl;
    cout << boolalpha << solution.isMatch(
        "aabcbcbcaccbcaabc",
        ".*a*aa*.*b*.c*.*a*"
    ) 
    << endl;
    cout << boolalpha << solution.isMatch("bbbba", ".*a*a") << endl;
    cout << boolalpha << solution.isMatch("", "c*c*") << endl;
    cout << boolalpha << solution.isMatch("", "") << endl;
    cout << boolalpha << solution.isMatch("", ".*.*.*") << endl;
    cout << boolalpha << solution.isMatch("adsfj", ".*.*.*") << endl;
    cout << boolalpha << solution.isMatch("a", ".*.*.*.") << endl;
    
    cout << boolalpha << solution.isMatch("a", "ab*") << endl;
    cout << boolalpha << solution.isMatch("aaaaa", "a*a") << endl;
    cout << boolalpha << solution.isMatch("ab", ".*") << endl;
    cout << boolalpha << solution.isMatch("aab", "c*a*b") << endl;
    cout << boolalpha << solution.isMatch("mississippi", "mis*is*p*.") << endl;
    cout << boolalpha << solution.isMatch("aa", "a") << endl;
    cout << boolalpha << solution.isMatch("aa", "aaa") << endl;
    return 0;
}
