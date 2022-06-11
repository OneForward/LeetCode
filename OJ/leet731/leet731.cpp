/*
leet731


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class MyCalendarTwo {
public:
    map<int, int> M;
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        M[start]++;
        M[end]--;
        auto cnt = 0;
        for (auto&& [_, freq]: M) {
            cnt += freq;
            if (cnt == 3) {
                M[start]--;
                M[end]++;
                return false;
            }
        }
        return true;
    }
};



int main(int argc, char const *argv[])
{
    auto my = MyCalendarTwo(); cout << boolalpha;
    cout << endl << my.book(10, 20); // returns true
    cout << endl << my.book(50, 60); // returns true
    cout << endl << my.book(10, 40); // returns true
    cout << endl << my.book(5, 15); // returns false
    cout << endl << my.book(5, 10); // returns true
    cout << endl << my.book(25, 55); // returns true

    return 0;
}
