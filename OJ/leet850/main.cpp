#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int arr[3] = {};
        for (const auto& x: bills) {
            switch (x) {
                case 5: arr[0] += 1; break;
                case 10: arr[1] += 1; if (arr[0] == 0) return false; else arr[0] -= 1; break;
                case 20: arr[2] += 1; 
                         if (arr[1] && arr[0]) {
                             arr[1] -= 1; arr[0] -= 1;
                         }
                         else if (arr[0] >= 3) {
                             arr[0] -= 3;
                         }
                         else return false;
                         break;
            }            
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> bills = {5, 5, 10, 10, 20};
    if (sol.lemonadeChange(bills)) cout << "true\n";
    else cout << "false\n";
    return 0;
}
