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
#include <random>
#include <functional>
#include <utility>
using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
template<class T> int CMP(T a[],const T b[],int n) { return memcmp(a,b,n*sizeof(T)); }
template<class T> void COPY(T a[],const T b[],int n) { memcpy(a,b,n*sizeof(T)); }
template<class T> void SET(T a[],int val,int n) { memset(a,val,n*sizeof(T)); }
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;
using VVI=vector<VI>;
using VS=vector<string>;




template<class Container>
void sort(Container& v) {
    sort(begin(v), end(v));
}
// namespace MyStd
// {
//     template<class Container>
//     void sort(Container& v) {
//         sort(begin(v), end(v));
//     }
// } // namespace MyStd

/**
 * @brief 链表类
 * 
 */
struct ListNode {
    int val ;
    ListNode *next ;
};

ListNode* toList(vector<int> v, int pos = -1) {
    ListNode head;
    ListNode* p = &head, *curr = nullptr;
    for (int i = 0; i < (int)v.size(); ++i) {
        p->next = new ListNode{v[i]};
        p = p->next; 
        if (i == pos) curr = p;
    }
    p->next = curr;
    return head.next;
}

ostream& operator<<(ostream& os, ListNode* p) {
    while (p)
    {
        os << p->val << " -> "; p = p->next;
    }
    os << "nullptr" << endl;
    return os;
}

void disp(ListNode* p, int pos = -1) {
    int cnt = 0; ListNode* curr = nullptr;
    while (p)
    {
        printf("%d -> ", p->val); p = p->next;
        if (p && p == curr) { printf("cycle\n"); return;}
        if (cnt == pos) curr = p; 
        cnt++;
    }
    printf("nullptr\n");
}


/**
 * @brief TreeNode: 二叉树结点类
 * 
 */

struct TreeNode {
    int val ;
    TreeNode *left ;
    TreeNode *right ;
};

const int null = -1;


TreeNode* toTree(const vector<int>& v) {
    if (v.empty()) return {};

    auto root = new TreeNode{v[0]};
    auto p = 1; int N = v.size();
    queue<TreeNode*> Q; Q.push(root);

    while (p < N) {
        auto node = Q.front(); Q.pop();
        auto lval = v[p++];
        
        if (lval != null) {
            node->left = new TreeNode{lval};
            Q.push(node->left);
        }

        if (p == N) break;

        auto rval = v[p++];
        if (rval != null) {
            node->right = new TreeNode{rval};
            Q.push(node->right);
        }
    }
    return root;
}

// overload for ostream of vectors
template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    int n = v.size();
    os << "{ ";
    for (int i = 0; i < n-1; ++i) os << v[i] << ", "; 
    if (n) os << v[n-1];
    os << " }";

    return os;
}


ostream& operator<<(ostream& os, TreeNode* root) {
    
    vector<string> s;
    queue<TreeNode*> Q; Q.push(root); 
    while (Q.size()) {
        auto len = Q.size();
        while (len--) {
            auto p = Q.front(); Q.pop();
            if (p == nullptr) s.push_back("null");
            else {
                s.push_back( to_string(p->val) );
                Q.push(p->left);
                Q.push(p->right);
            } 
        }
    }
    while ( s.size() and s.back() == "null") s.pop_back();
    os << s;
    return os;
}


void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}


/**
 * @ N 叉树 结点类
 * 
 * 
 */
class Node {
public:
    int val;
    vector<Node*> children;
};

Node* toNrayTree(const vector<int>& v) {
    if (v.empty()) return {};

    vector<Node*> Q; 
    for (const auto& x: v) {
        if (x != null) Q.push_back(new Node{x});
        else Q.push_back(nullptr);
    }

    auto p = 0;
    for (size_t i = 2; i < v.size(); i++)
    {
        if (v[i] == null) {
            ++p;
            while (Q[p] == nullptr) ++p;
        }
        Q[p]->children.push_back(Q[i]);
    }
    return Q[0];
}

ostream& operator<<(ostream& os, Node* root) {
    queue<Node*> Q; Q.push(root); 
    vector<string> s = {to_string(root->val), "null"};
    while (Q.size()) {
        auto len = Q.size();
        while (len--) {
            auto p = Q.front(); Q.pop();
            for (const auto& child: p->children) {
                if (child) Q.push(child), s.push_back(to_string(child->val));;
            }
            s.push_back("null");
        }
    }
    while ( s.size() and s.back() == "null") s.pop_back();
    os << s;
    return os;
}




// https://en.cppreference.com/w/cpp/utility/integer_sequence
template <class Tuple, size_t... i>
ostream& tuple_print(ostream& os, const Tuple& t, index_sequence<i...>) {
    os << "( ";
    (..., ( os << (i == 0 ? "" : ", ") << get<i>(t) ));
    os << " )";
    return os;
}

template <class... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    return tuple_print(os, t, index_sequence_for<Args...>{});
}




template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& v) {
    os << "{ " << v.first << ", " << v.second << " }";
    return os;
}


// overload for ostream of vectors of vectors
template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    int n = v.size();
    os << "{ ";
    for (int i = 0; i < n-1; ++i) os << v[i] << ", " << endl;
    if (n) os << v[n-1];
    os << " }";

    return os;
}


// type-safe get sign
template <typename T> int sgn(T x) {
    return (T(0) < x) - (x < T(0));
}





template<typename T, typename Container=std::deque<T> >
class iterable_queue : public std::queue<T,Container>
{
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};

// overload for ostream of queue
// template<class T>
// ostream& operator<<(ostream& os, const queue<T>& Q) {
//     iterable_queue<T> IQ(Q);
//     os << "{ ";
//     for (const auto& x: IQ) os << IQ << ", " << endl;
//     os << " }";

//     return os;
// }



// int main(int argc, char const *argv[])
// {
//     ListNode* l1 = toList( {1, 2, 3, 4, 5, 6}, 5 ); disp(l1, 5);
//     // ListNode* l1 = from( {1, 2, 3, 4, 5, 6} ); disp(l1);

//     // vector v = { 10,5,15,null,null,6,20 };
//     // vector v = { 1, null, 2, null, 3, 4 };
//     // vector v = { 2,1,3 };
//     // TreeNode* t1 = toTree(v); disp(t1);
    
//     return 0;
// }
