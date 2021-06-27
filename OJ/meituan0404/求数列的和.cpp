/*
meituan0404


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;


double f(double x, int m) {
    auto ans = 0.;
    while (m--) {
        ans += x;
        x = sqrt(x);
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    freopen("in1.txt", "r", stdin);

    int x, m;
    while (cin >> x >> m) {
        printf("%.2f\n", f(x, m));
    }
    
    return 0;
}
