/*
大整数类


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
#include <random>
#include <functional>
#include <utility>

using namespace std;

// 非负整数，输入未检查
struct BigInteger
{
    string data; 
    BigInteger(string s={}) {
        if (s.empty()) s = "0";
        for (auto p = s.rbegin(); p != s.rend(); ++p)
            data.push_back( *p - '0' );
    }

    friend istream& operator>>(istream& is, BigInteger& bigint) {
        string s; is >> s; 
        bigint = s; return is;
    }

    friend ostream& operator<<(ostream& os, const BigInteger& bigint) {
        for (int i = bigint.data.size() - 1; i >= 0; i--) os << (int) bigint.data[i];
        return os;
    }

    BigInteger& operator+=(const BigInteger& rhs) {
        int x = 0, i = 0, n = data.size(), m = rhs.data.size();
        string ans;
        for (; i < m or i < n; i++) {
            if (i < n) x += data[i];
            if (i < m) x += rhs.data[i];
            ans.push_back(x % 10); x /= 10; 
        }
        if (x) ans.push_back(x);
        data = ans;
        return *this;
    }
    
    friend BigInteger operator+(BigInteger& lhs, const BigInteger& rhs) {
        lhs += rhs;
        return lhs;
    }
};


int main()
{
    freopen("大整数加法_cases/case_05.in", "r", stdin);

    BigInteger A, B;
    cin >> A >> B;
    cout << (A + B);
    return 0;
}
