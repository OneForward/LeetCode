#ifndef _UBIG_INTEGER_
#define _UBIG_INTEGER_


#include <iostream>
using namespace std;

// 非负整数，输入未检查
struct UBigInteger
{
    static const int N = 1005;
    char data[N]{}; 
    int len{};

    UBigInteger(string s={}) {
        if (s.empty()) s = "0";
        for (int i = s.size() - 1; i >= 0; i--) data[len++] = s[i] - '0';
    }

    friend istream& operator>>(istream& is, UBigInteger& bigint) {
        string s; is >> s; 
        bigint = s; return is;
    }

    friend ostream& operator<<(ostream& os, const UBigInteger& bigint) {
        for (int i = bigint.len - 1; i >= 0; i--) os << (int) bigint.data[i];
        return os;
    }

    auto operator<=>(const UBigInteger& rhs) const {
        if (len > rhs.len) return 1;
        if (len < rhs.len) return -1;
        for (int i = len - 1; i >= 0; i--) {
            if (data[i] > rhs.data[i]) return 1;
            if (data[i] < rhs.data[i]) return -1;
        }
        return 0;
    }

    UBigInteger& operator+=(const UBigInteger& rhs) {
        int x = 0, n = len, m = rhs.len; len = 0;
        for (int i = 0; i < m or i < n; i++) {
            if (i < n) x += data[i];
            if (i < m) x += rhs.data[i];
            data[len++] = x % 10; x /= 10; 
        }
        if (x) data[len++] = x;
        return *this;
    }

    UBigInteger& operator-=(const UBigInteger& rhs) {
        // 需确保 lhs >= rhs
        int x = 0, n = len, m = rhs.len; len = 0;
        for (int i = 0; i < m or i < n; i++) {
            if (i < n) x += data[i];
            if (i < m) x -= rhs.data[i];
            if (x < 0) data[len++] = x + 10, x = -1; 
            else data[len++] = x, x = 0; 
        }
        return *this;
    }

    UBigInteger& operator/=(const UBigInteger& rhs) {
        // 需确保 lhs >= rhs
         
        return *this;
    }

    UBigInteger& operator*=(const UBigInteger& rhs) {
        int x = 0, n = len, m = rhs.len; len = n + m;
        char ans[N]{}; 
        for (int i = 0;  i < n; i++) {
            x = 0;
            for (int j = 0; j < m; j++) {
                x += ans[i + j] + data[i] * rhs.data[j];
                ans[i + j] = x % 10; x /= 10;
            }
            ans[i + m] = x;
        }
        
        for (int i = 0; i < len; i++) data[i] = ans[i];
        while (len and ans[len] == 0) len--; len++;
        return *this;
    }
    
    friend UBigInteger operator+(UBigInteger lhs, const UBigInteger& rhs) {
        lhs += rhs;
        return lhs;
    }

    friend UBigInteger operator-(UBigInteger lhs, const UBigInteger& rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend UBigInteger operator*(UBigInteger lhs, const UBigInteger& rhs) {
        lhs *= rhs;
        return lhs;
    }

};

#endif // !_UBIG_INTEGER_