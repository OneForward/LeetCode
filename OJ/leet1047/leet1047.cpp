#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char ch;
    Node* prev;
    Node* next;
    Node(char c, Node* p=nullptr, Node* n=nullptr): 
        ch{c}, prev{p}, next{n} {}
    
};

struct List
{
    Node* head;
    Node* tail;
    size_t len;
    List(): head{nullptr}, tail{nullptr}, len(0) {}

    void push_back(char ch) {
        len++;
        Node* node = new Node(ch, tail);
        if (head == nullptr) {
            head = tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }

    void remove(Node* node) {
        len--;
        Node* prev = node->prev;
        Node* next = node->next;
        if (prev) prev->next = next;
        else head = next; // node == head
        if (next) next->prev = prev;
        else tail = prev; // node == tail
        delete node; 
    }

    void print() {
        Node* p = head;
        while (p) {
            if (p->next) printf("%c -> ", p->ch);
            else printf("%c", p->ch);
            p = p->next;
        }
        printf("\n");
    }

    string to_string() {
        string s = "";
        Node* p = head;
        while (p) {            
            s.push_back(p->ch);
            p = p->next;
        }
        return s;
    }
};


class Solution {
public:
    string removeDuplicates(string s) {
        if (s.length() <= 1) return s;

        List L;
        for (auto ch: s) {
            L.push_back(ch);
        }
        // L.print();
        
        Node* p = L.head;
        Node* q = p->next;
        while (p && q) {
            if (p->ch == q->ch) {
                L.remove(p);
                L.remove(q);
                p = L.head;
                if (p) q = p->next;
            }
            else
                p = p->next,
                q = q->next;
        }
        // L.print();
        return L.to_string();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "aaaaaa";
    s = sol.removeDuplicates(s);
    printf("%s\n", "hello");
    printf("s.len = %d\n", s.length());
    cout << s << endl;
    return 0;
}
