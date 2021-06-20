#include <iostream>

using std::cout ; using std::endl;

struct Base {

    Base(): mem(0) { }
protected:
    int mem;
};

struct Derived : Base {

    Derived(int i) : mem(i){ }      // 初始化Drived::mem 为i , Base::mem被默认初始化为0

    int get_mem() { return mem;}             // 返回Drived::mem
    int get_base_mem() { return Base::mem;}  // 返回基类里面的mem
protected:
    int mem;   // 隐藏了base 里的mem成员
};

int main()
{
    Derived d(42);
    cout << d.get_mem() << endl;
    cout << d.get_base_mem() << endl;
}