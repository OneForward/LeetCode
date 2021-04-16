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
                v.push_back({Universal, '.'});
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

// 动态规划方法, 可以不需要预处理，时间无差
// 以下为有预处理的解答
class Solution {

public:

    bool isMatch(const string& s, const vector<State>& p) {

        int m = s.size(), n = p.size();
        vector<vector<int>> f = vector( m + 1, vector<int>(n + 1, false) );
        f[0][0] = true;

        auto matches = [&](int i, int j) {
            if (i==0) return false;
            if (p[j-1].data == '.') return true;
            return s[i-1] == p[j-1].data;
        };
        
        for (int i=0; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if ( p[j-1].state == NORMAL ) { // no *
                    if ( matches(i, j) ) f[i][j] = f[i-1][j-1] ;
                }
                else { // REPEATE or Universal
                    f[i][j] |= f[i][j-1]  ;
                    if ( matches(i, j) ) f[i][j] |= f[i-1][j] ;
                }
            }
        }
        return f[m][n];
    }

    bool isMatch(string s, string p) {
        auto [ok, new_p] = prepocess(p);
        return ok && isMatch(s, new_p);
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
