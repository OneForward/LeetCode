/*
数论


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

int gcd(int x, int y) {
    if (y) while ( (x %= y) and (y %= x) );
    return x + y;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
