/*
leet715


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

const int M = 1e9;
const int MX = 1e6+5;
class RangeModule {
public:
    int ls[MX],rs[MX],sum[MX];
    bool lazy[MX];
    int cnt,root;
    RangeModule() {
        cnt = 0;
        root = addNode();
    }
    void init_node(int p){
        ls[p] = rs[p] = sum[p] = 0;
        lazy[p] = false;
    }
    void spread(int p){
        if(lazy[p]){
            if(!ls[p]) ls[p] = addNode();
            if(!rs[p]) rs[p] = addNode();
            int l = ls[p],r = rs[p];
            if(sum[p]){
                sum[l] = sum[p]/2+(sum[p]&1);
                sum[r] = sum[p]-sum[l];
            }else{
                sum[l] = sum[r] = 0;
            }
            lazy[p] = false;
            lazy[l] = lazy[r] = true;
        }
    }
    int addNode(){
        ++cnt;
        init_node(cnt);
        return cnt;
    }
    void change(int l,int r,int L,int R,int& p,bool add){
        if(p==0){
            p = addNode();
        }
        if(L<=l&&r<=R){
            if(add){
                sum[p] = r-l+1;
            }else{
                sum[p] = 0;
            }
            lazy[p] = true;
            return ;
        }
        spread(p);
        int mid = (l+r)/2;
        if(L<=mid)change(l,mid,L,R,ls[p],add);
        if(R>mid) change(mid+1,r,L,R,rs[p],add);
        updateUp(p);
    }
    void updateUp(int p){
        int l = ls[p],r = rs[p];
        sum[p] = sum[l]+sum[r];
    }

    int query(int l,int r,int L,int R,int p){
        if(r<L||R<l||p==0){
            return 0;
        }
        if(L<=l&&r<=R){
            return sum[p];
        }
        spread(p);
        int mid = (l+r)/2;
        return query(l,mid,L,R,ls[p])+query(mid+1,r,L,R,rs[p]);
    }
    
    void addRange(int left, int right) {
        change(0,M,left,right-1,root,true);
    }
    
    bool queryRange(int left, int right) {
        int num = query(0, M, left, right-1, root);
        return num==(right-left);
    }
    
    void removeRange(int left, int right) {
        change(0,M,left,right-1,root,false);
    }
};

int main(int argc, char const *argv[])
{
    cout << boolalpha;

    RangeModule rangeModule;
    rangeModule.addRange(10, 20);
    rangeModule.removeRange(14, 16);
    rangeModule.queryRange(10, 14);
    rangeModule.queryRange(13, 15);
    rangeModule.queryRange(16, 17);

    return 0;
}