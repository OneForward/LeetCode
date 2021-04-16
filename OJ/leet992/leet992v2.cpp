#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

/*
sliding Window
要点在于思考[i1...i2...j]这段以j为终点的区间，
满足[i1...j]、[i2...j]都恰有K个数字，则[i1...i2]这个区间两端都是递增的
因此可以在O(N)时间内完成
*/


class Solution1 { // O(n^2)
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans = 0;
        unordered_set<int> S;

        for (int lft = 0; lft < A.size(); ++lft) {
            S.clear();
            for (int rht = lft; rht < A.size(); ++rht) {
                S.insert(A[rht]);
                if (S.size() == K) ans++;
                else if (S.size() > K) break;
            }
        }
        return ans;
    }
};

class Solution2 { // O(n)
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans = 0;
        unordered_map<int, int> S1, S2;
        int i1 = 0, i2 = 0, key;
        for (int j = 0; j < K-1; ++j) {
            key = A[j];
            if (S1.count(key)) S1[key]++;
            else S1[key] = 1;
            if (S2.count(key)) S2[key]++;
            else S2[key] = 1;
        }
//        if (S1.size() == K) ans = 1;
//for (auto x: A) printf("%d ", x); cout << endl;
//printf("%d\n", K);
//printf("S1.size = %d, S2.size = %d\n", S1.size(), S2.size());
        for (int j = K-1; j < A.size(); ++j) {
            key = A[j];
            if (S1.count(key)) S1[key]++;
            else S1[key] = 1;
            if (S2.count(key)) S2[key]++;
            else S2[key] = 1;
            
//            printf("S1.size = %d, S2.size = %d\n", S1.size(), S2.size());
            if (S1.size() < K) continue;
            
            while (S1.size() > K) {
                S1[A[i1]]--; 
                if (S1[A[i1]] == 0) S1.erase(A[i1]);
                i1++;
            }
            while (S2.size() >= K) {
                S2[A[i2]]--; 
                if (S2[A[i2]] == 0) S2.erase(A[i2]);
                i2++;
            }
//            printf("S2.size = %d, i2 = %d\n", S2.size(), i2);
            
            i2--; 
//            printf("A[i2] = %d\n", A[i2]);
            if (S2.count(A[i2])) S2[A[i2]]++;
            else S2[A[i2]] = 1;
            
            
//            printf("S2.size = %d, i2 = %d\n", S2.size(), i2);
//            printf("j = %d, i1 = %d, i2 = %d\n", j, i1, i2);
            ans += i2 - i1 + 1;
        }
        
        return ans;
    }
};


struct Counter {
    int  cnt;
    unordered_map<int, int> M;

    Counter():cnt(0) { }

    void insert(int key) {
        unordered_map<int, int>::iterator it = M.find(key);
        if (it == M.end()) M[key] = 1, cnt++;
        else {
            it->second++;
            if (it->second == 1) cnt++;
        }
    }

    void erase(int key) {
        unordered_map<int, int>::iterator it = M.find(key);
        it->second--;
        if (it->second == 0) cnt--;
    }

};

class Solution3 { // O(n)
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans = 0;
        Counter C1, C2;
        int i1 = 0, i2 = 0, key;
        for (int j = 0; j < K-1; ++j) {
            key = A[j]; C1.insert(key); C2.insert(key);
        }

        for (int j = K-1; j < A.size(); ++j) {
            key = A[j]; C1.insert(key); C2.insert(key);
            
            if (C1.cnt < K) continue;
            
            while (C1.cnt > K) {
                key = A[i1]; C1.erase(key); i1++;
            }
            
            while (C2.cnt >= K) {
                key = A[i2]; C2.erase(key); i2++;
            }      
  
            i2--; key = A[i2]; C2.insert(key);
            
            ans += i2 - i1 + 1;
        }
        
        return ans;
    }
};


struct Counters {
    int* freq;
    int cnt;

    Counters(int len): cnt(0) {
        freq = new int[len+1]();
    }


    void insert(int key) {
        freq[key]++;
        if (freq[key] == 1) cnt++;
    }

    void erase(int key) {
        freq[key]--;
        if (freq[key] == 0) cnt--;
    }
};

class Solution { // O(n)
                 // 注意 0 <= A[i] <= A.length()
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans = 0, len = A.size();
        Counters C1(len), C2(len);
        int i1 = 0, i2 = 0, key;
        for (int j = 0; j < K-1; ++j) {
            key = A[j]; C1.insert(key); C2.insert(key);
        }

        for (int j = K-1; j < len; ++j) {
            key = A[j]; C1.insert(key); C2.insert(key);
            
            if (C1.cnt < K) continue;
            
            while (C1.cnt > K) {
                key = A[i1]; C1.erase(key); i1++;
            }
            
            while (C2.cnt >= K) {
                key = A[i2]; C2.erase(key); i2++;
            }      
  
            i2--; key = A[i2]; C2.insert(key);
            
            ans += i2 - i1 + 1;
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    freopen("leet992/1.in", "r", stdin);

    
    int K;
    int size;
    cin >> size;
    vector<int> A(size, 0);
    for (int i=0; i<size; ++i) cin >> A[i];
    cin >> K;
    

    Solution solution;
    int ans = solution.subarraysWithKDistinct(A, K);

    cout << ans;
    // for (auto x: A) printf("%d ", x);

    return 0;
        
}
