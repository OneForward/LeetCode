/*
leet732


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class MyCalendarThree {
public:
    map<int, int> M;
    MyCalendarThree() {  }
    
    int book(int start, int end) {
        M[start]++;
        M[end]--;
        auto cnt = 0;
        auto max_cnt = 0;
        for (auto&& [_, freq]: M) {
            cnt += freq;
            max_cnt = max(max_cnt, cnt) ;
        }
        return max_cnt;
    }
};



int main(int argc, char const *argv[])
{
    MyCalendarThree myCalendarThree = MyCalendarThree(); 
    cout << endl << myCalendarThree.book(10, 20); // 返回 1 ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
    cout << endl << myCalendarThree.book(50, 60); // 返回 1 ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
    cout << endl << myCalendarThree.book(10, 40); // 返回 2 ，第三个日程安排 [10, 40) 与第一个日程安排相交，所以最大 k 次预订是 2 次预订。
    cout << endl << myCalendarThree.book(5, 15); // 返回 3 ，剩下的日程安排的最大 k 次预订是 3 次预订。
    cout << endl << myCalendarThree.book(5, 10); // 返回 3
    cout << endl << myCalendarThree.book(25, 55); // 返回 3

    
    return 0;
}
