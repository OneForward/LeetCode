/*
microsoft


*/
#include <string>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


int partition(vector<int>& v) {
    // O(N)
    // v.len > 0
    // swap(A[random_pos], A[-1]);
    auto x = v.back(); 
    int pos_of_x = 0;
    // [...] x [...]
    return pos_of_x;
}

void quickSort(vector<int>& v, int lft, int rht) {
    // [lft, rht)
    int pos = partition(v);
    quickSort(v, 0, pos);
    quickSort(v, pos, v.size());
}

// STL sort
// 5 个数 直接比较
// 10 个数 插入排序
// 再大的话快排

// bucket sort
// Time O(N)
// uniform distributed
// x \in v: x \in [0, 1]
// [0, 0.1)   -> 链表 -> 插入排序
// [0.1, 0.2) -> 
// ...
// [0.9, 1)


// 使用 桶排序 做数字字符串排序
// [1]
// [2]
// [3]
// 
// 

// input: vector<int>
// 拼接成最大的数字

// 998, 98, 9, 8
// 9 > 998 > 98 > 8 ?
// 9 998 

string solution(const vector<int>& v) {
    // O(N log N)

    auto cmp = [&](const string& x, const string& y) {
        return x + y > y + x;
    };

    vector<string> vs;
    for (auto&& x: v) vs.push_back(to_string(x));

    sort(ALL(vs), cmp); // N log N
    
    string s; 
    for (auto&& x: vs) s += x; 
    
    size_t i = 0;
    while (i < s.size() and s[i] == '0') ++i;

    return i == s.size() ? "0" : s.substr(i);
}


int main(int argc, char const *argv[])
{
    cout << solution({112, 12}) << endl;
    // 112  12 
    // 12112 > 11212

    cout << solution({998, 98, 9, 8}) << endl;
    cout << solution({998, 98, 0, 0}) << endl;
    cout << solution({0}) << endl;
    cout << solution({0, 0}) << endl;
    cout << solution({0, 0, 0}) << endl;
    cout << solution(vector<int>(10, 0)) << endl;
    cout << solution(vector<int>(10, 1)) << endl;
    cout << solution({1, 2, 3}) << endl;
    return 0;
}
