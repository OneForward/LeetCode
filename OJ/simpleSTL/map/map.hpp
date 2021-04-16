/**
 * implement a container like std::map
 * for the support of it->first.
 * See <http://kelvinh.github.io/blog/2013/11/20/overloading-of-member-access-operator-dash-greater-than-symbol-in-cpp/> for help.
 */
#ifndef SJTU_MAP_HPP
#define SJTU_MAP_HPP

#include <functional>
#include <cstddef>
#include "utility.hpp"
#include "exceptions.hpp"
namespace sjtu {

static const bool RED   = false;
static const bool BLACK = true;

template <class Key, class T>
struct RBNode
{
    typedef pair<const Key, T>        value_type;
    value_type* val;
    bool color;
    RBNode* lchild, *rchild, *parent;
    RBNode* prev, *next;

    RBNode(RBNode *_l=nullptr, RBNode *_r=nullptr, RBNode *_p=nullptr, bool _c = BLACK,
            RBNode *_prev = nullptr, RBNode *_n=nullptr):  val(nullptr), color(_c),
            lchild(_l), rchild(_r), parent(_p), prev(_prev), next(_n) {}

    RBNode(const value_type& _v,RBNode *_l=nullptr, RBNode *_r=nullptr, RBNode *_p=nullptr,
            bool _c = BLACK, RBNode *_prev = nullptr, RBNode *_n=nullptr): color (_c),
            lchild(_l), rchild(_r), parent(_p), prev(_prev), next(_n){
            val = new value_type(_v);
    }
    RBNode(RBNode* other, RBNode *_l=nullptr, RBNode *_r=nullptr, RBNode *_p=nullptr):
            color (other->color), lchild(_l), rchild(_r), parent(_p),
            prev(nullptr), next(nullptr){ // NOTE: it's NOT copy ctor!
            val = new value_type(*(other->val));
    }
    ~RBNode() {
        if (val) { delete val; val = nullptr; }
    }
};

template <class Key, class T, class Comp, bool is_const=false>
class map_iterator {
    template <class, class, class>
    friend class map;

    template <class, class, class, bool>
    friend class map_iterator;

    template <bool flag, class IsTrue, class IsFalse>
    struct choose;

    template <class IsTrue, class IsFalse>
    struct choose<true, IsTrue, IsFalse>  { typedef IsTrue type; };

    template <class IsTrue, class IsFalse>
    struct choose<false, IsTrue, IsFalse> { typedef IsFalse type; };
public:
    typedef pair<const Key, T>                                             value_type;
    typedef RBNode<Key, T>                                                 NodeType;
    typedef NodeType*                                                         NodePointer;
    typedef typename choose<is_const, const value_type &, value_type &>::type reference;
    typedef typename choose<is_const, const value_type *, value_type *>::type pointer;
private:
    NodePointer node, root; // root 用于标识该 iter 属于哪个 map
public:
    map_iterator(NodePointer _n=nullptr, NodePointer _r=nullptr): node(_n), root(_r) {}

    template <class _K, class _T, class _C, bool _is_const>
    map_iterator(const map_iterator<_K, _T, _C, _is_const> &other)
        { node = other.node; root = other.root; }

    ~map_iterator(){}

    map_iterator operator++(int) { // iter++
        map_iterator tmp(*this);
        ++(*this);
        return tmp;
    }

    map_iterator & operator++() { // ++iter
        if (node == nullptr or node->next == nullptr) throw invalid_iterator();
        node = node->next;
        return *this;
    }
    map_iterator operator--(int) { // iter--
        map_iterator tmp(*this);
        --(*this);
        return tmp;
    }

    map_iterator & operator--() { // --iter
        if (node == nullptr or node->prev == nullptr) throw invalid_iterator();
        node = node->prev;
        return *this;
    }

    reference operator*() const {
        if (node == nullptr) throw invalid_iterator();
        return *(node->val);
    }

    pointer operator->() const noexcept {
        if (node == nullptr) throw invalid_iterator();
        return node->val;
    }

    template <class _K, class _T, class _C, bool _is_const>
    bool operator==(const map_iterator<_K, _T, _C, _is_const> &y)
        { return node == y.node and root == y.root; }
    
    template <class _K, class _T, class _C, bool _is_const>
    bool operator!=(const map_iterator<_K, _T, _C, _is_const> &y)
        { return node != y.node or root != y.root; }

    template <class _K, class _T, class _C, bool _is_const>
    friend bool operator< (const map_iterator &x, const map_iterator<_K, _T, _C, _is_const> &y)
        { return Comp()(x->first, y->first); }

    template <class _K, class _T, class _C, bool _is_const>
    friend bool operator<=(const map_iterator &x, const map_iterator<_K, _T, _C, _is_const> &y)
        {return !(y < x);}

    template <class _K, class _T, class _C, bool _is_const>
    friend bool operator> (const map_iterator &x, const map_iterator<_K, _T, _C, _is_const> &y)
        {return y < x;}

    template <class _K, class _T, class _C, bool _is_const>
    friend bool operator>=(const map_iterator &x, const map_iterator<_K, _T, _C, _is_const> &y)
        {return !(x < y);}     
};


template<class Key, class T, class Compare = std::less<Key> >
class map {
public:
    typedef pair<const Key, T>                                       value_type;
    typedef RBNode<Key, T>                                           NodeType;
    typedef NodeType*                                                NodePointer;
    typedef map_iterator<Key, T, Compare, /*is_const=*/false >       iterator;
    typedef map_iterator<Key, T, Compare, /*is_const=*/true  >       const_iterator;
private:
    NodePointer root, NIL, start;
    int _size;
public:
    map():root(nullptr), NIL(new NodeType()), start(nullptr), _size(0) {}

    // map(initializer_list<value_type>, const Compare& = Compare()){}

    map(const map &other): NIL(new NodeType()), _size(other._size){
        if (other.root == nullptr) { root = nullptr; return; }
        copy_tree(root, other.root, NIL, other.NIL);
        link_tree();
    }

    map & operator=(const map &other) {
        if (this == &other or other.root == nullptr) return *this;
        clear();
        _size = other._size;
        copy_tree(root, other.root, NIL, other.NIL);
        link_tree();
        return *this;
    }

    ~map() {
        clear();
        delete NIL;
    }

    void clear() {
        if (root == nullptr) return;
        clear(root); _size = 0; start = NIL;
        NIL->prev = NIL->next = NIL->parent = NIL->lchild = NIL->rchild = root = nullptr;
    }

    T & at(const Key &key) {
        if (empty() or Compare()(last()->first, key) or Compare()(key, start->val->first))
            throw index_out_of_bound();
        return iterator(_at(key, root))->second;
    }

    const T & at(const Key &key) const {
        if (empty() or Compare()(clast()->first, key) or Compare()(key, start->val->first))
            throw index_out_of_bound();
        return const_iterator(_at(key, root))->second;
    }

    const T & operator[](const Key &key) const {
        if (empty() or Compare()(clast()->first, key) or Compare()(key, start->val->first))
            throw index_out_of_bound();
        return const_iterator(_at(key, root))->second;
    }

    iterator begin() { return iterator(start, root); }
    const_iterator cbegin() const { return const_iterator(start, root); }

    iterator end() { return iterator(NIL, root); }
    const_iterator cend() const { return const_iterator(NIL, root); }

    bool empty() const { return root == nullptr; }

    size_t size() const { return (size_t)_size; }

    size_t count(const Key &key) const {
        if (empty()) return 0;
        NodePointer node = root;
        while (node != NIL) {
            if (Compare()(key, node->val->first)) node = node->lchild;
            else if (Compare()(node->val->first, key)) node = node->rchild;
            else return 1;
        }
        return 0;
    }

    iterator find(const Key &key) {
        if (empty()) return end();
        NodePointer node = root;
        while (node != NIL) {
            if (Compare()(key, node->val->first)) node = node->lchild;
            else if (Compare()(node->val->first, key)) node = node->rchild;
            else return iterator(node, root);
        }
        return end();
    }

    const_iterator find(const Key &key) const {
        if (empty()) return cend();
        NodePointer node = root;
        while (node != NIL) {
            if (Compare()(key, node->val->first)) node = node->lchild;
            else if (Compare()(node->val->first, key)) node = node->rchild;
            else return const_iterator(node, root);
        }
        return cend();
    }

    T & operator[](const Key &key) {
        if (empty()) {
            root = new NodeType(NIL, NIL, NIL, BLACK, nullptr, NIL), _size++, NIL->prev = start = root;
            // Key 可以没有默认构造, 没有赋值重载, 必须有复制构造
            // T 必须有无参数的默认构造: T()
            root->val = new value_type(key, T());
            return root->val->second; // 返回值若写成iter->second是否会对性能有所削弱
        }
        NodePointer Z = root, P;
        while (Z != NIL) {
            P = Z;
            if (Compare()(key, Z->val->first)) Z = Z->lchild;
            else if (Compare()(Z->val->first, key)) Z = Z->rchild;
            else return Z->val->second; // alread exists
        }

        // Z is the insert pt, P is the parent of Z
        NodePointer newNode = new NodeType(NIL, NIL, P, RED); _size++;
        newNode->val = new value_type(key, T());
        if (Compare()(key, P->val->first)) {
            P->lchild = newNode;
            newNode->prev = P->prev; newNode->next = P; P->prev = newNode;
            if (newNode->prev) newNode->prev->next = newNode; //Check: null->newNode->P
            else start = newNode;
        }
        else {
            P->rchild = newNode;
            newNode->prev = P; newNode->next = P->next;
            P->next = newNode; newNode->next->prev = newNode;
        }

        if (P->color == RED) insert_fix_up(newNode);
        return newNode->val->second; // SUCCESS
    }

    pair<iterator, bool> insert(const value_type &value) {
        if (root == nullptr) {
            root = new NodeType(value, NIL, NIL, NIL, BLACK, nullptr, NIL), _size++, NIL->prev = start = root;
            return pair<iterator, bool>(iterator(root, root), true);
        }
        NodePointer Z = root, P;
        while (Z != NIL) {
            P = Z;
            if (Compare()(Z->val->first, value.first)) Z = Z->rchild;
            else if (Compare()(value.first, Z->val->first)) Z = Z->lchild;
            else return pair<iterator, bool>(iterator(Z, root), false); // alread exists
        }

        // Z is the insert pt, P is the parent of Z
        NodePointer newNode = new NodeType(value, NIL, NIL, P, RED); _size++; 
        if (Compare()(value.first, P->val->first)) {
            P->lchild = newNode;
            newNode->prev = P->prev; newNode->next = P; P->prev = newNode;
            if (newNode->prev) newNode->prev->next = newNode; //Check: null->newNode->P
            else start = newNode;
        }
        else {
            P->rchild = newNode;
            newNode->prev = P; newNode->next = P->next;
            P->next = newNode; newNode->next->prev = newNode;
        }

        if (P->color == RED) insert_fix_up(newNode);
        return pair<iterator, bool>(iterator(newNode, root), true); // SUCCESS
    }

    void erase(iterator pos) {
        if (empty() or root != pos.root or pos.node == NIL) throw index_out_of_bound();

        NodePointer Z = pos.node, X; // using node X to replace node Z
        bool prev_Z_color = Z->color;
        if (Z->lchild == NIL) X = Z->rchild, transplant(Z, X);
        else if (Z->rchild == NIL) X = Z->lchild, transplant(Z, X);
        else { // both children of Z aren't NIL, exchange Z and Y
            NodePointer Y = Z->next, ZP = Z->parent; X = Y->rchild;
            prev_Z_color = Y->color; set_color(Y, Z->color);
            if (Y->parent == Z) X->parent = Y;
            else transplant(Y, X), Y->rchild = Z->rchild, Y->rchild->parent = Y;
            transplant(Z, Y); Y->lchild = Z->lchild; Y->lchild->parent = Y; 
        }
        // NOTE: Z can't be NIL, thus Z must have Z->next
        if (Z->prev) Z->prev->next = Z->next;
        else // null->Z->Znext
            start = Z->next;
        Z->next->prev = Z->prev;

        if (prev_Z_color == BLACK) delete_fix_up(X);
        delete Z; _size--;
        if (root == NIL) root = nullptr, NIL->parent = nullptr;
    }

private:
    iterator last() { return iterator(NIL->prev, root); } // NOTE: 没有安全检查！
    const_iterator clast() const{ return const_iterator(NIL->prev, root); } // NOTE: 没有安全检查！

    void set_color(NodePointer node, bool color) { node->color = color; }

    void copy_tree(NodePointer& node, NodePointer tobecopyed, NodePointer parent, NodePointer other_NIL) {
        node = new NodeType(tobecopyed, NIL, NIL, parent);
        if (tobecopyed->lchild != other_NIL) copy_tree(node->lchild, tobecopyed->lchild, node, other_NIL);
        if (tobecopyed->rchild != other_NIL) copy_tree(node->rchild, tobecopyed->rchild, node, other_NIL);
    }

    void clear(NodePointer node) {
        if (node->lchild != NIL) clear(node->lchild);
        if (node->rchild != NIL) clear(node->rchild);
        if (node != NIL) delete node;
    }

    struct Queue
    {
        NodePointer* arr; int curIndex; NodePointer _start;
        Queue():curIndex(0){
            arr = new NodePointer[2];
            arr[0] = arr[1] = nullptr;
        };
        ~Queue() { if (arr) delete [] arr; }
        void push_back(NodePointer node) {
            arr[curIndex] = node;
            curIndex = (curIndex+1)%2;
            node->prev = arr[curIndex];
            if (arr[curIndex]) arr[curIndex]->next = node;
            else  // 说明刚插入第一个节点
                _start = node;
        }
    };

    void link_tree() {
        Queue Q;
        _link_tree(root, Q);
        start = Q._start;
        Q.push_back(NIL);
    }

    void _link_tree(NodePointer node, Queue& Q) {
        if(node->lchild != NIL) _link_tree(node->lchild, Q);
        Q.push_back(node);
        if(node->rchild != NIL) _link_tree(node->rchild, Q);
    }

    NodePointer _at(const Key& key, NodePointer node) const{
        if (node == NIL) throw index_out_of_bound();
        if (Compare()(key, node->val->first)) return _at(key, node->lchild);
        if (Compare()(node->val->first, key)) return _at(key, node->rchild);
        return node;
    }

    void left_rotate(NodePointer Z) {
        NodePointer P = Z->parent, R = Z->rchild, RL = Z->rchild->lchild;
        // R<->P
        R->parent = P;
        if (P == NIL) root = R; // Z is root
        else if (P->lchild == Z) P->lchild = R;
        else P->rchild = R;

        // RL<->Z
        Z->rchild = RL;
        if (RL != NIL) RL->parent = Z;

        // R<->Z
        Z->parent = R;
        R->lchild = Z;
    }

    void right_rotate(NodePointer Z) {
        NodePointer P = Z->parent, L = Z->lchild, LR = Z->lchild->rchild;

        // L<->P
        L->parent = P;
        if (P == NIL) root = L; // Z is root
        else if (P->rchild == Z) P->rchild = L;
        else P->lchild = L;

        // LR<->Z
        Z->lchild = LR;
        if (LR != NIL) LR->parent = Z;

        // L<->Z
        Z->parent = L;
        L->rchild = Z;
    }

    void transplant(NodePointer U, NodePointer V){
        // when using transplant(U, V), V should never be root
        V->parent = U->parent; // though V may be NIL,
                               // NIL->parent can be assigned temporarily
        if (U == root) // U may be root
            root = V;
        else if (U == U->parent->lchild) // o.w U->parent not NIL
            U->parent->lchild = V;
        else U->parent->rchild = V;
    }

    void insert_fix_up(NodePointer Z) {
        NodePointer P = Z->parent, U;
        while (Z != root and P->color == RED) {
            if (P == P->parent->lchild) {
                U = P->parent->rchild;
                if (U->color == RED) {//case 1
                    set_color(P, BLACK);
                    set_color(P->parent, RED);
                    set_color(U, BLACK);
                    Z = P->parent;
                }
                else {
                    if (Z == P->rchild) {// case 2, tri
                        Z = P;
                        left_rotate(P);
                        P = Z->parent;
                    }
                    // case 3, line
                    set_color(P->parent, RED);
                    set_color(P, BLACK);
                    right_rotate(P->parent);
                }
            }

            else {
                U = P->parent->lchild;
                if (U->color == RED) {//case 1
                    set_color(P, BLACK);
                    set_color(P->parent, RED);
                    set_color(U, BLACK);
                    Z = P->parent;
                }
                else {
                    if (Z == P->lchild) {// case 2, tri
                        Z = P;
                        right_rotate(P);
                        P = Z->parent;
                    }
                    // case 3, line
                    set_color(P->parent, RED);
                    set_color(P, BLACK);
                    left_rotate(P->parent);
                }
            }
            P = Z->parent;
        }
        set_color(root, BLACK);
    }

    void delete_fix_up(NodePointer X){
        NodePointer P, S;
        while (X != root and X->color == BLACK) {
            P = X->parent;
            if (X == P->lchild) {
                S = P->rchild; 
                if (S->color == RED) { //case 1
                    set_color(P, RED);
                    set_color(S, BLACK);
                    left_rotate(P); P = X->parent; S = P->rchild;
                }

                if (S->lchild->color == BLACK and S->rchild->color == BLACK) { // case 2
                    X = P;
                    set_color(S, RED);
                }
                else {
                    if (S->lchild->color == RED) { // case 3
                        set_color(S, RED);
                        set_color(S->lchild, BLACK);
                        right_rotate(S); P = X->parent; S = P->rchild;
                    }
                    // case 4
                    set_color(S, P->color);
                    set_color(P, BLACK);
                    set_color(S->rchild, BLACK);
                    left_rotate(P);
                    X = root;
                }
            }

            else {
                S = P->lchild; 
                if (S->color == RED) { //case 1
                    set_color(P, RED);
                    set_color(S, BLACK);
                    right_rotate(P); P = X->parent; S = P->lchild;
                }

                if (S->rchild->color == BLACK and S->lchild->color == BLACK) { // case 2
                    X = P;
                    set_color(S, RED);
                }
                else {
                    if (S->rchild->color == RED) { // case 3
                        set_color(S, RED);
                        set_color(S->rchild, BLACK);
                        left_rotate(S); P = X->parent; S = P->lchild;
                    }
                    // case 4
                    set_color(S, P->color);
                    set_color(P, BLACK);
                    set_color(S->lchild, BLACK);
                    right_rotate(P);
                    X = root;
                }
            }
        }
        set_color(X, BLACK);
    }
};

}

#endif
