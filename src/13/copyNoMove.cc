#include <utility>
#include <iostream>

class Foo
{
public:
    Foo() = default;
    Foo(const Foo&);
};

Foo::Foo(const Foo&)
{

    std::cout << "Foo copy ctor" << std::endl;
}

int main()
{
    Foo x;
    Foo y(x);        // 拷贝构造函数;x 是一个左值
    Foo z(std::move(x)); //拷贝构造函数， 因为没有移动构造函数；
}
