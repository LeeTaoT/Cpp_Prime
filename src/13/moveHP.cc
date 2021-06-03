#include <iostream>
#include <string>
#include <utility>

class HasPtr{
    friend void swap(HasPtr&, HasPtr&);

public:
    //默认构造函数
    HasPtr(const std::string &s = std::string()) : 
        ps(new std::string(s)), i(0){ }

    // 拷贝构造函数
    HasPtr(const HasPtr &p):
        ps(new std::string(*p.ps)), i(p.i) { }

    // 移动构造函数 
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i){ p.ps = 0;};

    HasPtr& operator=(HasPtr rhs)
    {
        swap(*this, rhs); 
        return *this;
    }

    //析构函数
    ~HasPtr() { delete ps;}


private:
    std::string *ps;
    int i ;

};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main()
{
    HasPtr hp("hi mom");
    HasPtr hp2(hp);

    hp = hp2;  // hp2 是一个左值；拷贝构造函数将会被调用
    hp = std::move(hp2); //移动构造函数
}