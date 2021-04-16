#ifndef SJTU_DEQUE_HPP
#define SJTU_DEQUE_HPP

#include "exceptions.hpp"

#include <cstddef>
#include <iostream>
namespace sjtu {

static const int BLOCK_SIZE = 500;

template <class T>
struct Node
{
    static const int N = BLOCK_SIZE;
    T** p;
    Node* prev, *next;
    int pStart, pFinish, curSize;

    Node(Node* _p=nullptr, Node *_n=nullptr):
            prev(_p), next(_n), pStart(0), pFinish(0), curSize(0){
        p=new T*[N];
        for (int i=0; i<N; ++i)
            p[i] = nullptr;
    }
    ~Node() {
        if (p) {
            for (int i=0; i<N; ++i) {
                if (p[i]) {
                    delete p[i];
                    p[i] = nullptr;
                }
            }
            delete [] p; p = nullptr;
        }
    }
};

template <class _ValueType, class _ValuePointer, class _Reference>
class deque_iterator {
    template <class T> friend class deque;
public:
    typedef _ValueType                  value_type;
    typedef _Reference                  reference;
    typedef _ValuePointer               value_pointer;
private:
    static const int N = BLOCK_SIZE;
    int offset;
    Node<value_type>* blk;
public:
    deque_iterator(int _offset=0, Node<value_type>* _blk=nullptr)
                : offset(_offset), blk(_blk) {}

    template <class _P, class _R>
    deque_iterator(const deque_iterator<value_type, _P, _R>& other)
        : offset(other.offset), blk(other.blk) {}

    deque_iterator& operator=(const deque_iterator &other){
        if (this == &other)
            return *this;
        offset = other.offset;
        blk = other.blk;
        return *this;
    };

    reference operator*() const {
        if ((blk->p[blk->pStart+offset]) == nullptr)
            throw invalid_iterator();
        return *((blk->p[blk->pStart+offset]));
    }

    value_pointer operator->() const {
        if ((blk->p[blk->pStart+offset]) == nullptr)
            throw invalid_iterator();
        return (blk->p[blk->pStart+offset]);
    }

    deque_iterator operator++(int) {
        deque_iterator ret;
        ret=*this;
        *this+=1;
        return ret;
    }

    deque_iterator& operator++() {
        (*this)+=1;
        return *this;
    }

    deque_iterator operator--(int) {
        deque_iterator ret;
        ret=*this;
        *this-=1;
        return ret;
    }

    deque_iterator& operator--() {
        *this-=1;
        return *this;
    }

    deque_iterator operator+=(int n) {
        deque_iterator ret;
        ret=*this+n;
        *this=ret;
        return *this;
    }

    deque_iterator operator-=(int n) {
        deque_iterator ret;
        ret=*this-n;
        *this=ret;
        return *this;
    }

    deque_iterator operator+(int n) const {
        // blk must within head and rear
        if (n < 0)   return operator-(-n);
        if (n == 0)  return *this;
        deque_iterator ret = *this;
        int cnt = blk->curSize - offset - 1;
        if ( n <= cnt or
            ( n == cnt+1 and is_rear(blk->next) and !is_full(blk)) )
            ret.offset += n;
        else
        {
            Node<value_type> *tmp = blk->next;
            while (cnt < n) {
                cnt += tmp->curSize;
                if (tmp->next and tmp->next->curSize and cnt < n) tmp = tmp->next;
                else break;
            }
            if (cnt < n - 1) throw index_out_of_bound();
            if (cnt == n-1 and !is_rear(tmp->next) and tmp->next->curSize == 0) { // 计算end()
                ret.offset = 0;
                ret.blk = tmp->next;
                // std::cout << "cnt = " << cnt << ", \nret.blk = "  << ret << ", \ntmp = " << tmp << "\n";
            }
            else {
                ret.offset = tmp->curSize + n - cnt - 1;
                ret.blk = tmp;
            }
        }
        return ret;
    }

    deque_iterator operator-(int n) const {
        // TO BE REVIEWED
        if (n <  0)  return operator+(-n);
        if (n == 0)  return *this;

        if (n>0 && offset==0 && blk->prev->prev==nullptr)
            throw index_out_of_bound();

        deque_iterator ret = *this;
        int cnt = offset;
        if ((n <= cnt))
            ret.offset -= n;
        else
        {
            Node<value_type> *tmp = blk->prev;
            while (cnt < n) {
                cnt += tmp->curSize;
                if (tmp->curSize and cnt < n) tmp = tmp->prev;
                else break;
            }
            if (cnt < n-1) throw index_out_of_bound();
            if (cnt == n-1 and is_end()) {
                ret.offset =  tmp->pStart;
                ret.blk = tmp;
            }
            else {
                ret.offset =  cnt- n;
                ret.blk = tmp;
            }
        }
        return ret;
    }

    int operator-(const deque_iterator &rhs) const {
        // TODO: check validity of rhs
        if (rhs.blk == nullptr or is_head(rhs.blk) or is_rear(rhs.blk))
            throw invalid_iterator();
        if (blk == rhs.blk)
            return offset-rhs.offset;

        Node<value_type> *backward = blk->prev, *forward = blk->next;
        int backwardCnt = offset, forwardCnt = blk->curSize - 1 - offset;

        while (backward->curSize and backward != rhs.blk)
            backwardCnt += backward->curSize,
            backward = backward->prev;

        if (backward == rhs.blk)
            return backwardCnt + backward->curSize - rhs.offset;

        while (forward->curSize and forward != rhs.blk)
            forwardCnt += forward->curSize,
            forward = forward->next;

        if (forward == rhs.blk)
            return -(forwardCnt + rhs.offset + 1);

        throw invalid_iterator();
    }

    friend deque_iterator operator+(int n, const deque_iterator& it)
        {return it + n;}

    reference operator[](int n) const
        {return *(*this + n);}

    friend bool operator==(const deque_iterator &x, const deque_iterator &y)
        {return (x.offset == y.offset && x.blk == y.blk);}

    friend bool operator!=(const deque_iterator &x, const deque_iterator &y)
        {return !(x == y);}

    friend bool operator< (const deque_iterator &x, const deque_iterator &y)
        {return y - x > 0;}

    friend bool operator<=(const deque_iterator &x, const deque_iterator &y)
        {return !(y < x);}

    friend bool operator> (const deque_iterator &x, const deque_iterator &y)
        {return y < x;}

    friend bool operator>=(const deque_iterator &x, const deque_iterator &y)
        {return !(x < y);}

private:
    bool is_rear() const
        {return blk->next and blk->next->next==nullptr;}

    bool is_rear(Node<value_type>* node) const
        {return node and node->next == nullptr;}

    bool is_head(Node<value_type>* node) const
        {return node and node->prev == nullptr;}

    bool is_full(Node<value_type>* node) const
        {return node->curSize == N;}

    bool is_end() const
        {return is_rear(blk->next) and blk->curSize==offset;}

    bool is_begin() const
        {return is_head(blk->prev) and offset == 0;}

    bool is_empty_deq() const
        {return is_begin() and is_end();}
};

template<class T>
class deque {
public:
    typedef deque_iterator<T,       T*,       T&>       iterator;
    typedef deque_iterator<T, const T*, const T&>       const_iterator;
private:
    static const int N = BLOCK_SIZE;
    Node<T> *head, *rear;
    int nBlocks, nElems;

public:
    deque():nBlocks(1), nElems(0){
        // default ctor
        // note: by default, there is one empty block
        head=new Node<T>;
        rear=new Node<T>;
        Node<T> *tmp=new Node<T>(head, rear);
        head->next = rear->prev = tmp;
    }

    deque(const deque &other):nBlocks(other.nBlocks),nElems(other.nElems){
        // std:: cout << "copy ctor\n" ;
        head = new Node<T>;
        rear = new Node<T>;
        Node<T>* tmp = new Node<T>(head, rear);
        head->next = rear->prev = tmp;

        Node<T>* otmp = other.head->next;
        while (otmp != other.rear)
        {
            for (int i=otmp->pStart; i<=otmp->pFinish; i++)
                if (otmp->p[i]) (tmp->p[i]) = new T(*(otmp->p[i]));
            setNode(tmp, otmp->pStart, otmp->pFinish, otmp->curSize);
            otmp = otmp->next;
            if (otmp == other.rear) break;
            Node<T>* mtmp=new Node<T>(tmp, nullptr);
            tmp->next=mtmp;
            tmp=mtmp;
        }
        tmp->next = rear;
        rear->prev = tmp;
    }

    deque &operator=(const deque &other){
        // std:: cout << "\nassign overload\n" ;
        if (this==&other)
            return *this;
        clear();
        nBlocks=other.nBlocks;
        nElems=other.nElems;

        Node<T>* tmp=head->next;
        Node<T>* otmp=other.head->next;

        while (otmp != other.rear)
        {
            for (int i=otmp->pStart; i<=otmp->pFinish; i++)
                if (otmp->p[i]) (tmp->p[i]) = new T(*(otmp->p[i]));
            setNode(tmp, otmp->pStart, otmp->pFinish, otmp->curSize);
            otmp = otmp->next;
            if (otmp == other.rear) break;
            Node<T>* mtmp=new Node<T>(tmp, nullptr);
            tmp->next=mtmp;
            tmp=mtmp;
        }
        tmp->next = rear;
        rear->prev = tmp;
        return *this;
    }

    ~deque() {
        clear();
        delete head->next; head->next=nullptr;
        delete head;
        delete rear;
        head = rear = nullptr;
    }

    bool empty() const {
        return (nElems==0);
    }

    size_t size() const {
        return nElems;
    }

    void clear() {
        while (!empty())
            pop_back();
    }

    T & at(const size_t &pos) {
        if (pos < 0 || pos >= nElems)
            throw index_out_of_bound();
        iterator ret(0, head->next);
        ret += pos;
        return *(ret);
    }

    const T & at(const size_t &pos) const {
        if (pos < 0 || pos >= nElems)
            throw index_out_of_bound();
        iterator ret(0, head->next);
        ret += pos;
        return *(ret);
    }

    T & operator[](const size_t &pos) {
        if (pos < 0 || pos >= nElems)
            throw index_out_of_bound();
        iterator ret(0, head->next);
        return *(ret += pos);
    }

    const T & operator[](const size_t &pos) const {
        if (pos < 0 || pos >= nElems)
            throw index_out_of_bound();
        iterator ret(0, head->next);
        ret += pos;
        return *(ret);
    }

    const T & front() const {
        if (empty())
            throw container_is_empty();
        iterator ret(0, head->next);
        return *(ret);
    }

    const T & back() const {
        if (empty())
            throw container_is_empty();
        if (rear->prev->curSize == 0 and rear->prev->prev->curSize > 0)
            return *iterator(rear->prev->prev->curSize-1, rear->prev->prev);
        else return *iterator(rear->prev->curSize-1, rear->prev);
    }

    iterator begin() {
        if (empty())
            return end();
        iterator ret(0, head->next);
        return ret;
    }

    const_iterator cbegin() const {
        if (empty())
            return cend();
        const_iterator ret(0, head->next);
        return ret;
    }

    iterator end() {
        if (rear->prev->curSize == 0) return iterator(0, rear->prev);
        else return iterator(rear->prev->curSize, rear->prev);
    }

    const_iterator cend() const {
        if (rear->prev->curSize == 0) return const_iterator(0, rear->prev);
        else return const_iterator(rear->prev->curSize, rear->prev);
    }

    iterator insert(iterator pos, const T &value) {

        if (nElems == 0 && pos != begin())
           throw index_out_of_bound();
       if (!is_valid_iterator(pos, /*include_end = */ true))
            throw invalid_iterator();

        if (pos == begin()) {
            push_front(value);  return begin();
        }

        if (pos == end()) {
            push_back(value); return last();
        }

        Node<T>* pnode = head->next;
        while (pnode != pos.blk) pnode = pnode->next;
        T* val_ptr = new T(value);

        if (pnode->curSize == N) { // pnode is full, which implies pnode->next is not rear
            if (pnode->next->curSize == N or is_rear(pnode->next)) { // pnode->next is full
                insert_blank_block_between(pnode, pnode->next);
                insert_at_block_at(pnode->next, pnode->p[N-1], 0);
                for (int i = N-1; i > pos.offset+pnode->pStart; --i)
                    pnode->p[i] = pnode->p[i-1];
                pnode->p[pos.offset+pnode->pStart] = val_ptr;
            }
            else {
                // pnode->next is not full
                insert_at_block_front(pnode->next, pnode->p[N-1]);
                // if pnode->next is now full and happens to be rear->prev
                if (pnode->next->curSize == N and is_rear(pnode->next->next))
                    insert_blank_block_between(pnode->next, pnode->next->next);
                for (int i = N-1; i > pos.offset+pnode->pStart; --i)
                    pnode->p[i] = pnode->p[i-1];
                pnode->p[pos.offset+pnode->pStart] = val_ptr;
            }
        }
        else { //pnode is not full
            if (pnode->curSize == N-1 and is_rear(pnode->next))
                insert_blank_block_between(pnode, pnode->next);
            insert_at_block_at(pnode, val_ptr, pos.offset);
        }
        nElems++;
        return pos;

    }

    iterator erase(iterator pos) {
        /*************************************************
            合法iterator和非空序列(nElems>=1)情形下分支
            1. pos为尾部: pop_back(), 返回 end()
            2. pos不在尾部: 前移, pop_back(), 返回 pos+1;
        ***************************************************/

        if (empty()) throw container_is_empty();
        if (!is_valid_iterator(pos)) throw invalid_iterator();

        if (pos == last())
        {   // NOTE: 此处可以处理只有一个元素的情况
            pop_back();
            return end();
        }
        nElems--;

        if (pos.blk->curSize == pos.offset + 1) {
            iterator ret(0, pos.blk->next);
            destroy_pointer(pos.blk, pos.blk->pStart + pos.offset);
            return ret;
        }
        destroy_pointer(pos.blk, pos.blk->pStart + pos.offset);
        return pos;
    }

    void push_back(const T &value) {
        /********************************************************************

        ********************************************************************/
        nElems++;
        T* val_ptr = new T(value);
        Node<T>* rear_prev = rear->prev;
        if (rear_prev->curSize == 0)
            insert_at_block_at(rear_prev, val_ptr, 0);

        else if (rear_prev->curSize == N-1) {
            insert_blank_block_between(rear_prev, rear),
            insert_at_block_back(rear_prev, val_ptr);
        }
        else if (rear_prev->curSize == N) {
            insert_blank_block_between(rear_prev, rear),
            insert_at_block_at(rear->prev, val_ptr, 0);
        }
        else
            insert_at_block_back(rear_prev, val_ptr);
    }

    void push_front(const T &value) {
        /************************************************************

        ***************************************************************/
        nElems++;
        T* val_ptr = new T(value);
        Node<T>* head_next = head->next;
        if (head_next->curSize == 0)
            insert_at_block_at(head_next, val_ptr, 0);
        else if (head_next->curSize == N) {
            insert_blank_block_between(head, head_next);
            insert_at_block_at(head->next, val_ptr, 0);
        }
        else {
            if (head_next->curSize == N-1 and is_rear(head_next->next))
                insert_blank_block_between(head_next, rear);
            insert_at_block_front(head_next, val_ptr);
        }

    }

    void pop_back() {
        if (empty())
            throw container_is_empty();

        destroy_pointer(last());
        nElems--;
    }

    void pop_front() {
        if (empty())
            throw container_is_empty();

        destroy_pointer(begin());
        nElems--;
    }

private:
    void setNode(Node<T>*& p, int pStart=-1, int pFinish=-1, int curSize=-1) {
        p->pStart = pStart;
        p->pFinish = pFinish;
        p->curSize = curSize;
    }

    void destroy_pointer(iterator iter) {
        destroy_pointer(iter.blk, iter.blk->pStart+iter.offset);
    }

    void destroy_pointer(Node<T>*& block, int pIndex) {
        // 假设已经确认过合法性: pStart <= index <= pFinish, curSize >= 1
        if (block->p[pIndex]) {
            delete block->p[pIndex];
            block->p[pIndex] = nullptr;
            block->curSize--;

            if (!is_rear(block->next) and block->next->curSize == 0)
                destroy_block(block->next);
            if (block->curSize == 0) {
                // 空块保留的情况：
                // 1. 自己是rear->prev并且上一块已满
                // 2. 自己是最后一个块
                if (block->next->curSize > 0 or
                    (block->prev->curSize > 0 and block->prev->curSize < N-1))
                    destroy_block(block);
                return;
            }

            if (block->curSize == 1) {
                if (block->pStart == pIndex and N / 2 != block->pFinish)
                    block->p[N/2] = block->p[block->pFinish],
                    block->p[block->pFinish] = nullptr;
                else if (block->pFinish == pIndex and N / 2 != block->pStart)
                    block->p[N/2] = block->p[block->pStart],
                    block->p[block->pStart] = nullptr;

                block->pStart = block->pFinish = N/2;
                return;
            }
            if (block->pStart == pIndex) {
                block->pStart++; return;
            }
            if (block->pFinish == pIndex) {
                block->pFinish--; return;
            }

            if (2 * pIndex > block->pStart + block->pFinish) {
                for (int i = pIndex; i < block->pFinish; ++i)
                    block->p[i] = block->p[i+1];
                block->p[block->pFinish] = nullptr;
                block->pFinish--;
            }
            else {
                for (int i = pIndex; i > block->pStart; --i)
                    block->p[i] = block->p[i-1];
                block->p[block->pStart] = nullptr;
                block->pStart++;
            }
        }
    }

    void destroy_block(Node<T>* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        nBlocks--;
    }

    void insert_blank_block_between(Node<T>* prevNode, Node<T>* nextNode) {
        Node<T>* node = new Node<T>(prevNode, nextNode);
        prevNode->next = nextNode->prev = node;
        nBlocks++;
    }

    void insert_at_block_at(Node<T>*& node, T* p, int pOffset, bool backward=false) {
        // 假设已经确认过块有空余区: curSize < N
        // 且index合法：0 <= pOffset < curSize, 默认后移后插入
        // if (node->curSize >= N) throw sjtu::container_is_empty();
        if (node->curSize == 0) { // 插入空块, 默认插在中间
            node->p[N/2] = p; node->curSize = 1;
            node->pStart = node->pFinish = N/2;
            return;
        }
        int pStart = node->pStart, pFinish = node->pFinish, curSize = node->curSize;
        // if (pFinish >= N or pStart < 0 or pOffset < 0 or pOffset > curSize) {
        //     // printNode(node);
        //     throw sjtu::container_is_empty();
        // }
        if (pFinish < N-1 and (2 * pOffset > curSize or pStart == 0))
        { //选择后移
            for (int i=pFinish+1; i>pOffset+pStart; --i)
                node->p[i] = node->p[i-1];
            node->p[pOffset+pStart] = p;
            node->pFinish++;
            node->curSize++;
        }
        else {//选择前移
            for (int i=pStart-1; i<pOffset+pStart-1; ++i)
                node->p[i] = node->p[i+1];
            node->p[pOffset+pStart-1] = p;
            node->pStart--;
            node->curSize++;
        }
    }

    void insert_at_block_front(Node<T>*& node, T* p) {
        // 假设已经确认过块有空余区
        // if (node->curSize >= N) throw sjtu::container_is_empty();
        if (node->curSize == 0) {
            node->p[N/2] = p;
            node->pStart = node->pFinish = N/2;
        }
        else if (node->pStart > 0)
            node->p[node->pStart-1] = p,
            node->pStart--;
        else {
            for (int i = 0; i < node->curSize; ++i)
                node->p[(node->pFinish+N) / 2 - i] = node->p[node->pFinish - i];

            node->pFinish = (node->pFinish+N) / 2;
            node->pStart = node->pFinish - node->curSize;
            node->p[node->pStart] = p;
            int i = node->pStart-1;
            while (i >= 0) node->p[i] = nullptr, --i;
        }
        node->curSize++;
    }

    void insert_at_block_back(Node<T>*& node, T* p) {
        // if (node->curSize >= N) throw sjtu::container_is_empty();
        // 假设已经确认过块有空余区
        if (node->curSize == 0) {
            node->p[N/2] = p;
            node->pStart = node->pFinish = N/2;
        }
        else if (node->pFinish < N-1)
            node->p[node->pFinish+1] = p,
            node->pFinish++;
        else {
            for (int i = 0; i < node->curSize; ++i)
                node->p[node->pStart / 2 + i] = node->p[node->pStart + i];

            node->pStart /= 2;
            node->pFinish = node->pStart + node->curSize;
            node->p[node->pFinish] = p;
            int i = node->pFinish+1;
            while (i < N) node->p[i] = nullptr, ++i; // TODO: can be optimized
        }
        node->curSize++;
    }

    bool is_rear(Node<T>* node) const{
        return node != nullptr and node->next == nullptr;
    }

    bool is_head(Node<T>* node) const{
        return node != nullptr and node->prev == nullptr;
    }

    bool is_node_secure(Node<T>* node) const{
        if (node == nullptr or node->p == nullptr) return true;

        for (int i = 0; i < N; ++i) {
            if (i < node->pStart ) {
                if (node->p[i]) throw sjtu::container_is_empty();
            }
            else if (i > node->pFinish) {
                if (node->p[i]) throw sjtu::container_is_empty();
            }
            else {
                if (node->curSize == 0) {
                   if (node->p[i]) throw sjtu::container_is_empty();
                }
                else if(node->p[i] == nullptr) throw sjtu::container_is_empty();
            }
        }
        if (node->curSize == 0) return node->curSize == node->pFinish - node->pStart;
        else return node->curSize == node->pFinish - node->pStart + 1;
    }
public:
    bool is_clear_secure() const {
        if (head->curSize or rear->curSize or head->next->curSize) throw sjtu::container_is_empty();
        if (nElems != 0 or nBlocks != 1) throw sjtu::container_is_empty();
        Node<T>* pnode = head;
        while (pnode) {
            if (!is_node_secure(pnode)) throw sjtu::container_is_empty();
            pnode = pnode->next;
        }
        return true;
    }

    bool is_valid_iterator(const iterator& iter, bool include_end = false) const{
        if (iter.offset < 0 or iter.offset >= N or iter.blk == nullptr) return false;
        if (is_rear(iter.blk) or is_head(iter.blk)) return false;
        if (include_end) {
            if (iter.offset > iter.blk->curSize) return false;
            if (iter.offset == iter.blk->curSize) return iter.is_end();
        }
        return iter.offset < iter.blk->curSize or iter.is_begin();
    }

    bool is_memory_secure() {
        if (head->curSize or rear->curSize) throw sjtu::container_is_empty();
        Node<T>* pnode = head;
        while (pnode) {
            if (!is_node_secure(pnode)) throw sjtu::container_is_empty();
            pnode = pnode->next;
        }
        return true;
    }

    iterator last() {
        if (rear->prev->curSize == 0 and rear->prev->prev->curSize > 0)
            return iterator(rear->prev->prev->curSize-1, rear->prev->prev);
        else return iterator(rear->prev->curSize-1, rear->prev);
    }

    void printNode(Node<T>* &node) {
        if (node == head) std::cout << "head->";
        if (node == rear) std::cout << "rear->";
        if (node) {
            std::cout << "&node = " << node << ", prev = " << node->prev << ", next = " << node->next << "";
            std::cout << ", pStart = " << node->pStart << ""
               << ", pFinish = " << node->pFinish
               << ", curSize = " << node->curSize << ", "
               << "T** p = " << node->p << "\n";
               ;
             // if (node->p)
             //     for (int i=0; i<N; ++i)
             //         if (node->p[i]) std::cout << "p[" << i << "] = " << node->p[i] << "\n";
            std::cout << "\n";
        }
    }

    void printDeqNodes() {
        Node<T>* node = head;
        while (node) printNode(node), node=node->next;
    }

     friend std::ostream& operator<<(std::ostream& os, const deque<T>& deq) {

         os << "val: ";
         for (int i=0; i<deq.size(); ++i) os << deq[i] << ", ";
         os << "\n\n";
         return os;
     }
};

}

#endif
