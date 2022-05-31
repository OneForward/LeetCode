/*
lcof14


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    string alienOrder(const vector<string>& words) {
        // 建树
        bool tree[26][26]{};
        int N = words.size();
        
        int indegree[26]{};
        bool exists[26]{};
        
        string ans;
        queue<int> Q;
        for (int i = 1; i < N; ++i) {
            int M = min(words[i-1].size(), words[i].size());
            int j = 0;
            for (; j < M; ++j) {
                if (words[i-1][j] == words[i][j]) continue;
                tree[words[i-1][j] - 'a'][words[i][j] - 'a'] = true;
                break;
            }
            if (j == M and words[i-1].size() > words[i].size()) goto bad;
        }

        for (auto&& word: words) {
            for (auto&& ch: word) {
                exists[ch - 'a'] = true;
            }
        }

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (tree[i][j]) {
                    indegree[j]++;
                }
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (not exists[i]) indegree[i] = -1;
        }

        // bfs + 拓扑排序
        // bool visited[26]{};
        
        for (int i = 0; i < 26; ++i) {
            if (indegree[i] == 0) {
                Q.push(i); exists[i] = false;
            }
        }

        while (Q.size()) {
            int len = Q.size();
            while (len--) {
                auto root = Q.front(); Q.pop(); 
                ans += (root + 'a');
                for (int i = 0; i < 26; ++i) {
                    if (tree[root][i]){
                        if (not exists[i]) goto bad; // 环
                        indegree[i]--;
                        if (indegree[i] == 0) {
                            Q.push(i); exists[i] = false;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < 26; ++i) {
            if (exists[i]) goto bad;
        }

        return ans;
        bad: return "";
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.alienOrder({"wrt","wrf","er","ett","rftt"}) << endl;
    cout << sol.alienOrder({"z","x"}) << endl;
    cout << sol.alienOrder({"z","z"}) << endl;
    cout << sol.alienOrder({"z","x","z"}) << endl;
    cout << sol.alienOrder({"ac","ab","zc","zb"}) << endl;
    cout << sol.alienOrder({"abc","ab",}) << endl;
    return 0;
}
