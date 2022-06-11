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
    using Tuple = tuple<int, int>;
    using VT = vector<Tuple>;
    VT v;
    MyCalendar() {}
    
    bool book(int start, int end) {
        for (auto&& [lft, rht]: v) {
            if (end <= lft or start >= rht) continue;
            return false;
        }
        v.push_back({start, end});
        return true;
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
