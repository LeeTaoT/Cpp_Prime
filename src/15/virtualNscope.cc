#include <iostream>
using std::cout ; using std::endl;

class Base {
public:
    virtual int fcn();

};

int Base::fcn() { cout << "Base::fcn()" << endl; return 0;} 

class D1 : public Base {

public :
    int fcn(int);
    virtual void f2();
};

int D1::fcn(int) { cout << "D1::fcn(int)" << endl; return 0;}
void D1::f2() {cout << "D2::f2()" << endl;}

class D2 final : public D1 {

public :
    int fcn(int); // 非虚拟函数，隐藏了D1::fcn(int)
    int fcn()  override ; // 重载Base 类中的fcn函数
    void f2() override ; // 重载D1中的虚拟函数f2;
};

int D2::fcn(int) {cout << "D2::fcn(int)" << endl; return 0;}
int D2::fcn() { cout << "D2::fcn()" << endl; return 0;}
void D2::f2() { cout << "D2::f2()" << endl;}

int main()
{

    D1 dobj , *dp = &dobj;
    dp->fcn(42) ;   // 静态调用D1::fcn(int)

    Base bobj ; 
    D1 d1obj ;
    D2 d2obj ;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();   // 虚函数调用， 运行时调用Base::fcn
    bp2->fcn();   // 虚函数调用, 运行时调用Base::fcn 
    bp3->fcn();   // 虚函数调用, 运行时调用D2::fcn

    D1 *d1p = &d1obj;
    D2 *d2p = &d2obj;
    d1p->f2();    // 虚函数调用， 运行时调用D1::f2() 
    d2p->f2();    // 虚函数调用, 运行时调用D2::f2()

    Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
    p2->fcn(42);    // 静态绑定,调用D1::fcn(int)
    p3->fcn(42);    // 静态绑定,调用D2::fcn(int)

    Base *bp = &d1obj; D1 *dp1 = &d2obj; D2 *dp2 = &d2obj;
    dp1->fcn(10);   // 静态调用D1::fcn(int)
    dp2->fcn(10);   // 静态调用D2::fcn(int)




}