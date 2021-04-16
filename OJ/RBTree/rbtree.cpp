#include <iostream>
#include <vector>
#include <queue>
#include <random>

using namespace std;

const int BLACK = 0;
const int RED = 1;
const int FAILED = -1;
const int ALREADY_EXISTS = 0;
const int NOT_EXISTS = 0;
const int SUCCESS = 1;

template <class T> class RBNode;
template <class T> class RBTree;
template <class T> ostream & operator<<(ostream &, const RBNode<T>&);
template <class T> ostream & operator<<(ostream &, const RBTree<T>&);

template <class T>
class RBNode {
public:
	T data;
	RBNode<T>* parent;
	RBNode<T>* lchild;
	RBNode<T>* rchild;
	int color;

	RBNode(const T& _d = T(), RBNode<T>* _p = NULL, RBNode<T>* _l = NULL, RBNode<T>* _r = NULL, int _c = BLACK) :
		data(_d), parent(_p), lchild(_l), rchild(_r), color(_c) {}
	~RBNode() {}
	friend ostream & operator<< <>(ostream & os, const RBNode& node);
};

template <class T>
class RBTree
{
public:
	RBTree();
	RBTree(const vector<T>& arr);
	~RBTree();
	RBNode<T>* get_root() const;
	int find(const T& _data) const;
	int get_maximum(T& retmax) const;
	int get_minimum(T& retmin) const;
	int get_successor(const T& k, T& ret) const;
	int get_predecessor(const T& k, T& ret) const;
	int insert(const T& _data);
	int remove(const T& _data);
	int inorder_tree_walk();
	friend ostream& operator<< <>(ostream& os, const RBTree& rbtree);

private:
	RBNode<T> * root;
	static RBNode<T>* NIL;
	void transplant(RBNode<T>* U, RBNode<T>* V);
	void left_rotate(RBNode<T>* node);
	void right_rotate(RBNode<T>* node);
	void insert_fix_up(RBNode<T>* node);
	void delete_fix_up(RBNode<T>* node);
	void set_color(RBNode<T>* node, int c);
	void make_empty(RBNode<T>* root);
	int find(RBNode<T>* node, const T& _data) const;
	int get_color(RBNode<T>* node) const;

};

template <class T>
RBNode<T>* RBTree<T>::NIL = new RBNode<T>();

template <class T>
RBTree<T>::RBTree()
{
	root = NULL;
}

template<class T>
RBTree<T>::RBTree(const vector<T>& arr)
{
	root = NULL;
	for (T _data : arr) insert(_data);
}

template<class T>
RBTree<T>::~RBTree()
{
}

template<class T>
int RBTree<T>::insert(const T & _data)
{
	RBNode<T>* newNode = new RBNode<T>(_data, NIL, NIL, NIL, RED);
	if (root == NULL) { root = newNode, set_color(root, BLACK); return SUCCESS; }
	RBNode<T>* Z = root, *P;
	while (Z != NIL) {
		P = Z;
		if (Z->data < _data) Z = Z->rchild;
		else if (Z->data > _data) Z = Z->lchild;
		else return ALREADY_EXISTS; // alread exists
	}

	// Z is the insert pt, P is the parent of Z
	newNode->parent = P;
	if (_data < P->data) P->lchild = newNode;
	else P->rchild = newNode;

	if (P->color == RED) insert_fix_up(newNode);
	return SUCCESS;
}

template<class T>
int RBTree<T>::remove(const T & _data)
{
	if (root == NULL) return FAILED;
	RBNode<T>* Z = root;
	while (Z != NIL) {
		if (Z->data < _data) Z = Z->rchild;
		else if (Z->data > _data) Z = Z->lchild;
		else break; // found delete location
	}

	if (Z == NIL) return NOT_EXISTS; // not exists

	RBNode<T> *X; // using node X to replace node Z
	if (Z->lchild == NIL) X = Z->rchild;
	else if (Z->rchild == NIL) X = Z->lchild;
	else { // both children of Z aren't NIL
		RBNode<T> *P = Z; Z = Z->rchild;
		while (Z->lchild != NIL) Z = Z->lchild;
		P->data = Z->data;
		X = Z->rchild;
	}

	transplant(Z, X);
	if (Z->color == BLACK) delete_fix_up(X);
	delete Z;
	if (root == NIL) root = NULL, NIL->parent = NULL;
	return SUCCESS;

}

template<class T>
int RBTree<T>::find(const T & _data) const
{
	if (root == NULL) return -1;
	return find(root);
}

template<class T>
void RBTree<T>::insert_fix_up(RBNode<T> * Z)
{
	RBNode<T>* P = Z->parent, *U;
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

template<class T>
void RBTree<T>::delete_fix_up(RBNode<T> * X)
{
	RBNode<T>* P, *S;
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

template<class T>
int RBTree<T>::get_color(RBNode<T> * node) const
{
	return node->color;
}

template<class T>
void RBTree<T>::set_color(RBNode<T> * node, int c)
{
	node->color = c;
}

template<class T>
int RBTree<T>::find(RBNode<T>* node, const T & _data) const
{
	if (node == NIL) return -1;
	if (_data > node) return find(node->rchild, _data);
	else if (_data < node) return find(node->lchild, _data);
	else return 1;
}

template<class T>
void RBTree<T>::make_empty(RBNode<T>* root)
{
	if (root == NULL or root == NIL) return;
	make_empty(root->lchild);
	make_empty(root->rchild);
	delete root;
	root = NULL;
}

template<class T>
RBNode<T>* RBTree<T>::get_root() const
{
	return root;
}

template<class T>
void RBTree<T>::transplant(RBNode<T>* U, RBNode<T>* V)
{   // when using transplant(U, V), V should never be root
	V->parent = U->parent; // though V may be NIL,
						   // NIL can be assigned a parent temporarily
	if (U == root) // U may be root
		root = V;
	else if (U == U->parent->lchild) // o.w U->parent not NIL
		U->parent->lchild = V;
	else U->parent->rchild = V;

}

template<class T>
void RBTree<T>::left_rotate(RBNode<T>* Z)
{
	//	if (Z->rchild == NIL) return;

	RBNode<T>* P = Z->parent, *R = Z->rchild, *RL = Z->rchild->lchild;

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

template<class T>
void RBTree<T>::right_rotate(RBNode<T> * Z)
{
	//	if (Z->lchild == NIL) return;

	RBNode<T>* P = Z->parent, *L = Z->lchild, *LR = Z->lchild->rchild;

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


template<class T>
ostream & operator<<(ostream & os, const RBTree<T> & rbtree)
{
	if (rbtree.root == NULL) os << "It's null tree\n";
	else os << *rbtree.root << "\n";
	return os;
}

template<class T>
ostream & operator<<(ostream & os, const RBNode<T>& node)
{
	//    os << node.data << ", ";
	//    os << *node.lchild;
	//    os << *node.rchild;
	queue<RBNode<T>*> q;
	RBNode<T>* null = new RBNode<T>();
	RBNode<T>* pNode = new RBNode<T>(node);
	q.push(pNode); q.push(null);
	do {
		pNode = q.front(); q.pop();
		if (pNode->data == T()) os << '\n', q.push(pNode);
		else {
			os << pNode->data << '(';
			if (pNode->color == BLACK) os << "BLACK)\t";
			else os << "RED)\t";
			if (pNode->lchild and pNode->lchild->data != T()) q.push(pNode->lchild);
			if (pNode->rchild and pNode->rchild->data != T()) q.push(pNode->rchild);
		}
	} while (q.size() > 1);
	return os;
}

int main() {
	//	vector<int> arr = { 1,2,3,4,5,6,7,8,9,100,4, 5,2,100,9,10,33,333,3333 };
	vector<int> arr;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 1000);

	int SIZE = 99;
	while (SIZE--) arr.push_back(dis(gen));

	RBTree<int> rbtree(arr);
	cout << rbtree << endl;

	cout << "arr.size() = " << arr.size() << endl;
	for (int _data : arr)
		cout << "I'm removing " << _data << "\n",
		rbtree.remove(_data),
		rbtree.insert(dis(gen)),
		cout << "after removing " << _data << "\n" << rbtree << "\n";
}

