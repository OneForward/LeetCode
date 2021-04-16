/*
leet1603


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class ParkingSystem {
public:
    int data[4];
    ParkingSystem(int big, int medium, int small): data{0, big, medium, small} {
        
    }
    
    bool addCar(int carType) {
        if (data[carType]) {data[carType]--; return true;}
        return false;
    }
};


int main(int argc, char const *argv[])
{
    cout << boolalpha;
    ParkingSystem parkingSystem =  ParkingSystem(1, 1, 0);
    cout << endl << parkingSystem.addCar(1); // 返回 true ，因为有 1 个空的大车位
    cout << endl << parkingSystem.addCar(2); // 返回 true ，因为有 1 个空的中车位
    cout << endl << parkingSystem.addCar(3); // 返回 false ，因为没有空的小车位
    cout << endl << parkingSystem.addCar(1); // 返回 false ，因为没有空的大车位，唯一一个大车位已经被占据了

    return 0;
}
