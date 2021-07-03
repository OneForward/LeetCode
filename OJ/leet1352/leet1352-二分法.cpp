/*
leet1352


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

int fpower(int x, int n) {
    if (x == 0 and n) return 0;

    int ans = 1;
    while (n) {
        if (n & 1) ans *= x;
        n >>= 1; if (n) x *= x; 
    }
    return ans;
}

class ProductOfNumbers {
public:
    int n = 0;
    vector<int> v[101]{};
    ProductOfNumbers() { }
    
    void add(int x) {
        v[x].push_back(n++);
    }
    
    int getProduct(int k) {
        int ans = 1;
        for (int i = 0; i <= 100; i++)   
        {
            int pos = v[i].end() - lower_bound(ALL(v[i]), n - k);
            ans *= fpower(i, pos);
            if (ans == 0) break;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */


int main(int argc, char const *argv[])
{
    ProductOfNumbers productOfNumbers =  ProductOfNumbers();
    productOfNumbers.add(3);        // [3]
    productOfNumbers.add(0);        // [3,0]
    productOfNumbers.add(2);        // [3,0,2]
    productOfNumbers.add(5);        // [3,0,2,5]
    productOfNumbers.add(4);        // [3,0,2,5,4]
    cout << endl << productOfNumbers.getProduct(2); // 返回 20 。最后 2 个数字的乘积是 5 * 4 = 20
    cout << endl << productOfNumbers.getProduct(3); // 返回 40 。最后 3 个数字的乘积是 2 * 5 * 4 = 40
    cout << endl << productOfNumbers.getProduct(4); // 返回  0 。最后 4 个数字的乘积是 0 * 2 * 5 * 4 = 0
    productOfNumbers.add(8);        // [3,0,2,5,4,8]
    cout << endl << productOfNumbers.getProduct(2); // 返回 32 。最后 2 个数字的乘积是 4 * 8 = 32 

    return 0;
}
