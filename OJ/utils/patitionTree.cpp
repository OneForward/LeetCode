
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 100001;
const int DEEP = 18;
//DEEP = ceil(log2(MAXN))+1
//ceil是天花板函数,ceil(x)的取值为大于等于x的最小整数
using namespace std;
typedef struct{
    int num[MAXN];  //num记录第k层当前位置的元素的值
    int cnt[MAXN]; //cnt记录元素所在区间的当前位置之前进入左孩子的个数
}PartitionTree;
PartitionTree tree[DEEP];
int sorted[MAXN];   //对原来集合中的元素排序后的值。

void build(int deep, int lft, int rht){
    if(lft == rht) return ;
    int mid = (lft + rht) >> 1;
    int scnt = mid - lft + 1;
    //为了使划分树的每一节点的元素等于区间长度
    //我们对于相等的数，就不能全部放到左子树
    //只能放一部分给左子树
    //下面是计算能够放几个与sorted[mid]相等的数到左子树
    for(int i = lft; i <= rht; i++){
        if(tree[deep].num[i] < sorted[mid]) scnt--;
    }
    int p = lft, r = mid + 1;
    for(int i = lft, cnt_in_left = 0; i <= rht; i++){
        int num = tree[deep].num[i];
        //如果小于sorted[mid]或者相等且scnt!=0，那么则放入左子树
        if(num < sorted[mid] || (num == sorted[mid] && scnt)){
            if(num == sorted[mid]) scnt--;
            cnt_in_left++;
            tree[deep+1].num[p++] = num;
        }//否则进入右子树
        else tree[deep+1].num[r++] = num;
        //记录元素所在区间的当前位置之前进入左孩子的个数
        tree[deep].cnt[i] = cnt_in_left;
    }
    //递归建树
    build(deep+1, lft, mid);
    build(deep+1, mid+1, rht);
}

bool comp(const int& lhs, const int& rhs) {
    return lhs < rhs;
}
void merge(int A[], int B[], int lft,  int mid, int rht) {
    int start1 = lft, end1 = mid, start2 = mid+1, end2 = rht, k = lft;
    while (start1 <= end1 and start2 <= end2) B[k++] = (comp(A[start1], A[start2])) ? A[start1++] : A[start2++];
    while (start1 <= end1) B[k++] = A[start1++];
    while (start2 <= end2) B[k++] = A[start2++];
}

void merge_sort(int A[], int B[], int lft, int rht) {
    if (lft == rht) {
        B[lft] = A[lft]; return;
    }
    int mid = (lft + rht) / 2;
    // printf("mid = %d\n", mid);
    merge_sort(A, B, lft, mid);
    merge_sort(A, B, mid+1, rht);
    merge(A, B, lft, mid, rht);
    for (int i=lft; i<=rht; ++i) A[i] = B[i];
}

int main(int argc, char const *argv[])
{
    int A[] = {0, 4, 2, 5, 7, 1, 8, 3, 6};
    int N = 8;
    for (int i=1; i<=N; ++i)  tree[1].num[i] = A[i];
    merge_sort(A, sorted, 1, N);
    for (int i=1; i<=N; ++i) printf("%d, ", sorted[i]); printf("\n");
    
    

    build(1, 1, N);
    for (int d=1; d<=4; ++d)
    {
        for (int i=1; i<=N; ++i)
            printf("%d, ", tree[d].num[i]);
        printf("\n");
    }
printf("\n");
    for (int d=1; d<=4; ++d)
    {
        for (int i=1; i<=N; ++i)
            printf("%d, ", tree[d].cnt[i]);
        printf("\n");
    }   
    return 0;
}
