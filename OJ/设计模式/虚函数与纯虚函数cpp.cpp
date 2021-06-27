/*
设计模式


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

struct A
{
    // static A* singleton;
    virtual ~A() =0  ;
    virtual string f() =0 ;
};

A::~A(){ cout << "~A\n"; }
string A::f(){ return "A"; }

struct B:A
{
    static B* singleton;
    static B* getB( );
    ~B() {cout << "~B\n";}
    string f()  { return  "B"; }
};

B* B::singleton = new B;
B* B::getB() { return new B; }

struct C:B
{
    ~C(){ cout << "~C\n"; }
    using A::f;
    string f()  { 
        return A::f() + "C"; 
    }
};


int main(int argc, char const *argv[])
{
    // A a;
    A* c = new C ;
    cout << c->f() << endl;
    delete c;
    return 0;
}
