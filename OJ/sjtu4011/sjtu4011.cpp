/*
    A[h+1, K] = A[h, 1]
    A[h+1, k] = sum(A[h, K..K-k+1])
    [大数加法]
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

struct BigNum
{
    char arr[255] = {};
    int size = 0;

    BigNum() {}
    BigNum(const char* num)  {
        while (num[size] != '\0') size++;
        for (int i=size; i>=1; --i) arr[size-i] = num[i-1] - '0';
    }

    BigNum(const BigNum& other) {
        size = other.size;
        for (int i=0; i<size; ++i) arr[i] = other.arr[i];
    }

    BigNum& operator=(const BigNum& other) {
        if (this == &other) return *this;
        size = other.size;
        for (int i=0; i<size; ++i) arr[i] = other.arr[i];
    }

    void print() {
        // printf("size = %d, num = ", size);
        for (int i=size-1; i>=0; --i) printf("%c", arr[i]+'0'); printf("\n");
    }
};

BigNum operator+(const BigNum& lhs, const BigNum& rhs) {
    if (lhs.size > rhs.size) return (rhs + lhs);

    int size = 0, carry = 0, lhsPart = 0;
    BigNum ans;
    while (size < rhs.size) {
        if (size < lhs.size) lhsPart = lhs.arr[size];
        else lhsPart = 0;
        ans.arr[size] = lhsPart + rhs.arr[size] + carry;
        if (ans.arr[size] >= 10) ans.arr[size] -= 10, carry = 1;
        else carry = 0;
        // printf("ans.arr[%d] = %d, size = %d\n", size, ans.arr[size], size);
        size++;
    }
    if (carry) ans.arr[size++] = 1;

    ans.size = size;
    return ans;
}

int H, K;
BigNum bigA[55], bigTmp[55];

int main(int argc, char const *argv[])
{
    cin >> K >> H;

    for (int i=1; i<=K; ++i) bigA[i] = BigNum("1");
    for (int h=2; h<=H; ++h) {
        bigTmp[K] = bigA[1];
        for (int i=K-1; i>=1; --i) bigTmp[i] = bigTmp[i+1] + bigA[K+1-i];
        for (int i=1; i<=K; ++i) bigA[i] = bigTmp[i];
    }
    bigA[1].print();

    return 0;
}
