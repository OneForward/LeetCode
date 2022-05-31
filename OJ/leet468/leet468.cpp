/*
leet468


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    bool isValidIPv4(const string& ip) {
        int cnt = 1;
        int sublen = 0;
        int num = 0;
        for (auto&& ch: ip) {
            if (ch == '.') {
                if (sublen == 0) return false;
                cnt++, sublen = 0, num = 0; continue;
            }
            if (not isdigit(ch)) return false;
            sublen++; 
            num = num * 10 + ch - '0';
            if (num >= 256 or (num < 10 and sublen == 2)) return false;
            if (cnt > 4) return false;
        }
        return cnt == 4 and sublen > 0;
    }
    bool isValidIPv6(const string& ip) {
        int cnt = 1;
        int sublen = 0;
        for (auto ch: ip) {
            if (ch == ':') {
                if (sublen == 0) return false;
                cnt++, sublen = 0; continue;
            }
            sublen++; ch = tolower(ch);
            if (not (isdigit(ch) or ('a' <= ch and ch <= 'f'))) return false;
            if (sublen > 4 or cnt > 8) return false;
        }
        return cnt == 8 and sublen > 0;
    }
    string validIPAddress(const string& queryIP) {
        if (isValidIPv4(queryIP)) return "IPv4";
        if (isValidIPv6(queryIP)) return "IPv6";
        return "Neither";
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.validIPAddress("172.16.254.1") << endl;
    cout << sol.validIPAddress("1.0.1.") << endl;
    cout << sol.validIPAddress("1..0.1") << endl;
    cout << sol.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << endl;
    cout << sol.validIPAddress("256.256.256.256") << endl;

    return 0;
}
