/*
leet729


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class MyCalendar {
public:
    map<int, int> M;
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto lp = M.lower_bound(end);
        if (lp == M.begin() or start >= prev(lp)->second) {
            M[start] = end;
            return true;
        }
        else return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main(int argc, char const *argv[])
{
    auto my = MyCalendar();
    cout << boolalpha;
    cout << my.book(10, 20) << endl;
    cout << my.book(15, 25) << endl;
    cout << my.book(20, 30) << endl;
    return 0;
}
