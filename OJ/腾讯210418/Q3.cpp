#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;



int main()
{
    freopen("in.txt", "r", stdin);

    double R1, X1, Y1, X3, Y3;
    double R2, X2, Y2;
    cin >>  R1 >> X1 >> Y1 >> X3 >> Y3;
    
    auto d = sqrt((X3-X1)*(X3-X1) + (Y3-Y1)*(Y3-Y1));
    if (d >= R1) {
        printf("%f %f %f\n", X1, Y1, R1);
    }
    else {
        auto alpha = R1 / d / 2 - 0.5;
        X2 = -alpha * X3 + (1 + alpha) * X1;
        Y2 = -alpha * Y3 + (1 + alpha) * Y1;
        R2 = (R1 + d) / 2;
        printf("%f %f %f\n", X2, Y2, R2);
    }




    
    
    return 0;
}
