/*
拼多多0808


*/

// #include "../utils/LeetCpp.utils.hpp"


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;




int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    int N;
    string ops;
    cin >> N >> ops;

    // char OK = '$';
    deque<char> D1, D2;
    vector<int> ans;
    for (auto&& ch: ops) {
        if (ch == 'L') {
            if (D1.size()) D2.push_front(D1.back()), D1.pop_back();
        }
        else if (ch == 'R') {
            if (D2.size()) D1.push_back(D2.front()), D2.pop_front();
        }
        else if (ch == 'D') {
            if (D1.size()) D1.pop_back();
        }
        else {
            D1.push_back(ch);
        }

        using Pair = pair<int, int>;
        stack<Pair> S;
        const int LFT = -1;
        const int RHT = -2;
        int max_depth = 0;
        for (auto&& ch: D1) {
            if (ch == '(') S.push({LFT, 0});
            else {
                if (S.empty()) S.push({RHT, 0});
                else {
                    auto [ch_int, depth] = S.top();
                    if (ch_int == LFT) {
                        S.pop(); max_depth = max(max_depth, depth + 1);
                        if (not S.empty() and S.top().first == LFT) S.top().second = depth + 1;
                    }
                    else  S.push({RHT, 0});
                }
            }
        }
        for (auto&& ch: D2) {
            if (ch == '(') S.push({LFT, 0});
            else {
                if (S.empty()) S.push({RHT, 0});
                else {
                    auto [ch_int, depth] = S.top();
                    if (ch_int == LFT) {
                        S.pop(); max_depth = max(max_depth, depth + 1);
                        if (not S.empty() and S.top().first == LFT) S.top().second = depth + 1;
                    }
                    else  S.push({RHT, 0});
                }
            }
        }

        ans.push_back(S.size() ? -(int)S.size() : max_depth);
    }

    for (auto&& x: ans) {
        cout << x << ' ';
    }



    return 0;
}
