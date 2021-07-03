/*
leet912


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
    int partition(vector<int>&A, int lft, int rht) {
        swap(A[rht], A[rand() % (rht - lft + 1) + lft]);
        auto x = A[rht];
        int j = lft;
        for (int i = lft; i < rht; i++) {
            if (A[i] < x) swap(A[i], A[j++]);
        }
        swap(A[j], A[rht]);
        return j;
    }

    void quickSort(vector<int>& A, int lft, int rht) {
        if (lft >= rht) return;
        auto mid = partition(A, lft, rht);
        quickSort(A, lft, mid - 1);
        quickSort(A, mid + 1, rht);
    }

public:
    vector<int> sortArray(vector<int>& A) {
        quickSort(A, 0, A.size() - 1);
        return A;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   

    vector v = {5,1,1,2,0,0};
    cout << sol.sortArray(v) << endl;
    return 0;
}
